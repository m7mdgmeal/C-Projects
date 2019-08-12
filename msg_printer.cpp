#include "msg_printer.h"

//*************************************************************************************************************//
//************************************* MsgPrinter Class ******************************************************//
//*************************************************************************************************************//

MsgPrinter::MsgPrinter(const string &message) : message(message)
{
}

MsgPrinter::MsgPrinter(const char *message) : message(message)
{
}
MsgPrinter::MsgPrinter(const MsgPrinter &msgprint) : message(msgprint.get_message())
{
}

MsgPrinter::~MsgPrinter()
{
    cout << "End of MsgPrinter: " << this->message << endl;
}

//*************************************************************************************************************//
//************************************** MsgPrinterSurrounding Class ******************************************//
//*************************************************************************************************************//

MsgPrinterSurrounding::MsgPrinterSurrounding(const string &msg) : MsgPrinter(msg), m_before(NULL), m_after(NULL)
{
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const string &msg, const char *b_msg, const char *a_msg) : MsgPrinter(msg)
{
    clone_msg(b_msg, &(this->m_before));
    clone_msg(a_msg, &(this->m_after));
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &copy) : MsgPrinter(copy.get_message())
{
    clone_msg(copy.get_before(), &(this->m_before));
    clone_msg(copy.get_after(), &(this->m_after));
}

void MsgPrinterSurrounding::print() const
{

    this->print_before();

    MsgPrinter::print();

    this->print_after();
}
void MsgPrinterSurrounding::clone_msg(const char *base_msg, char **required_msg)
{

    (*required_msg) = new char[strlen(base_msg) + 1];
    strcpy((*required_msg), base_msg);
}
MsgPrinterSurrounding::~MsgPrinterSurrounding()
{
    delete[] m_after;
    delete[] m_before;
    cout << "End of MsgPrinterSorrounding";
    MsgPrinter::print();
}

MsgPrinterSurrounding &MsgPrinterSurrounding::operator=(const MsgPrinterSurrounding & msg_p_s)
{
    delete[] this->m_after;
    delete[] this->m_before;

    
    this->set_message(msg_p_s.get_message());

    clone_msg(msg_p_s.get_before(), &(this->m_before));
    clone_msg(msg_p_s.get_after(), &(this->m_after));
    return *this;
}
