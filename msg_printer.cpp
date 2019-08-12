#include "msg_printer.h"

//*************************************************************************************************************//
//*************************************************************************************************************//
//************************************* MsgPrinter Class ******************************************************//
//*************************************************************************************************************//
//*************************************************************************************************************//

//************************************** Initialization methods ************************************************//
//ctor that take a const refrencse to string object and initialize the messate with it
MsgPrinter::MsgPrinter(const string &message) : message(message)  
{
}
//ctor char takes char * as a string and initialize the message string
MsgPrinter::MsgPrinter(const char *message) : message(message)
{
}
//copy ctor that takes const reference to MsgPrinter object and clone to the message the message in the object
MsgPrinter::MsgPrinter(const MsgPrinter &msgprint) : message(msgprint.get_message())
{
}
//dtor that prints the end of the object with the message
MsgPrinter::~MsgPrinter()
{
    cout << "End of MsgPrinter: " << this->message << endl;
}



//*************************************************************************************************************//
//*************************************************************************************************************//
//************************************** MsgPrinterSurrounding Class ******************************************//
//*************************************************************************************************************//
//*************************************************************************************************************//



//*************************************************************************************************************//
//************************************** Initialization methods ************************************************//

//ctor that takes 1 args, initialize the base class with this argument and initialize the before and after to Null
MsgPrinterSurrounding::MsgPrinterSurrounding(const string &msg) : MsgPrinter(msg), m_before(NULL), m_after(NULL)
{
}
//ctor that takes 3 args, initialize the base class with this 1st argument and alocate before and after in order to clone the messages(b_msg,a_msg)

MsgPrinterSurrounding::MsgPrinterSurrounding(const string &msg, const char *b_msg, const char *a_msg) : MsgPrinter(msg)
{
    clone_msg(b_msg, &(this->m_before));     // alocate and clone to member before the b_msg string
    clone_msg(a_msg, &(this->m_after));      // alocate and clone to member after the a_msg string  
}

// copy ctor , that initialize the base class with get method , and alocate before and after in order to clone the messages(b_msg,a_msg)
MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &copy) : MsgPrinter(copy.get_message())
{
    clone_msg(copy.get_before(), &(this->m_before));   // alocate and clone to member before the before msg in copy object
    clone_msg(copy.get_after(), &(this->m_after));     // alocate and clone to member after the after msg in copy object
}


//dtor deltes the alocated memory and print nice destrunt message + prints the base message
MsgPrinterSurrounding::~MsgPrinterSurrounding()
{
    delete[] m_after;
    delete[] m_before;
    cout << "End of MsgPrinterSorrounding";
    MsgPrinter::print();
}



//*************************************************************************************************************//
//************************************* override methods ******************************************************//

void MsgPrinterSurrounding::print() const                 // override the print function from the base class
{
    this->print_before();                                // prints the before msg
    MsgPrinter::print();                                 // prints the Base message 
    this->print_after();                                 // prints the after message
}



//*************************************************************************************************************//
//**************************************** private methods ****************************************************//

// take char* as a string , and point to char* , alocate the pointer to the size of the string and copy the contant .
void MsgPrinterSurrounding::clone_msg(const char *base_msg, char **required_msg)
{
    (*required_msg) = new char[strlen(base_msg) + 1];
    strcpy((*required_msg), base_msg);
}


//*************************************************************************************************************//
    //****************************** operators *************************************//
    // operator =
MsgPrinterSurrounding &MsgPrinterSurrounding::operator=(const MsgPrinterSurrounding & msg_p_s)
{
    delete[] this->m_after;                      // delete the alocated memory 
    delete[] this->m_before;

    
    this->set_message(msg_p_s.get_message());   // set the base message as the msg_p_s object

    clone_msg(msg_p_s.get_before(), &(this->m_before));   // alocate + clone to before msg
    clone_msg(msg_p_s.get_after(), &(this->m_after));       // alocate + clone to after msg
    return *this;                                           // return *this 
}
