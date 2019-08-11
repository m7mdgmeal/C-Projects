#ifndef MSG_PRINTER_H
#define MSG_PRINTER_H

#include <iostream>
#include <string>
#include<new>
#include<string.h>

using namespace std;



//*************************************************************************************************************//
//************************************* MsgPrinter Class ******************************************************//
//*************************************************************************************************************//

class MsgPrinter
{
private:
    const string message; // a const string that holds the message string
public:
    MsgPrinter(const string& message); // ctor that takes string as a string object
    MsgPrinter(const char *message);  // ctor that takes string as a char * object
    ~MsgPrinter();                    // dtor

    virtual void print(); // virtual print function , print the message
};



//*************************************************************************************************************//
//*************************************************************************************************************//



//*************************************************************************************************************//
//************************************** MsgPrinterSurrounding Class ******************************************//
//*************************************************************************************************************//

class MsgPrinterSurrounding : public MsgPrinter
{
private:
    char *m_before;
    char *m_after;
    void fill_msg(const char *base_msg,char ** required_msg);
public:
    MsgPrinterSurrounding(const string &);
    MsgPrinterSurrounding(const string &,const char *,const char *);
    ~MsgPrinterSurrounding();
};


//********************************** inlines MsgPrinterSurrounding Class **************************************//

//*************************************************************************************************************//
//*************************************************************************************************************//

#endif



//************************************* inlines MsgPrinter Class **********************************************//

inline void MsgPrinter::print()
{
    cout << "Message: " << this->message << endl;
}

