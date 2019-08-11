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

MsgPrinter::~MsgPrinter()
{
    cout << "End of MsgPrinter: " << this->message << endl;
}

//*************************************************************************************************************//
//************************************** MsgPrinterSurrounding Class ******************************************//
//*************************************************************************************************************//

MsgPrinterSurrounding::MsgPrinterSurrounding(const string &msg) : MsgPrinter(msg)
{
    m_before=NULL;
    m_after=NULL;
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const string &msg, const char *b_msg,const char *a_msg):MsgPrinter(msg)
{
    fill_msg(b_msg,&(this->m_before));
    fill_msg(a_msg,&(this->m_after));

    cout<<"I am befome"<<this->m_before<<endl;
    cout<<"I am after"<<this->m_after<<endl;
}

void MsgPrinterSurrounding::fill_msg(const char *base_msg,char ** required_msg){
        (*required_msg)=new char[strlen(base_msg)+1];
        strcpy((*required_msg),base_msg);
    }
MsgPrinterSurrounding::~MsgPrinterSurrounding()
{
    delete[] m_after;
    delete[] m_before;
    cout << "End of MsgPrinterSorrounding";
    MsgPrinter::print();
}