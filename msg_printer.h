#ifndef MSG_PRINTER_H
#define MSG_PRINTER_H

#include <iostream>
#include <string>
#include <new>
#include <string.h>

using namespace std;

//*************************************************************************************************************//
//************************************* MsgPrinter Class ******************************************************//
//*************************************************************************************************************//

class MsgPrinter
{
private:
    string message; // a const string that holds the message string
public:
    MsgPrinter(const string &message); // ctor that takes string as a string object
    MsgPrinter(const char *message);   // ctor that takes string as a char * object
    MsgPrinter(const MsgPrinter &);    // c.ctor
    virtual ~MsgPrinter();             // dtor

    const string get_message() const;
    virtual void print() const; // virtual print function , print the message
    void set_message(const string &);
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
    void clone_msg(const char *base_msg, char **required_msg);
    
protected:
    virtual void print_before() const;
    void print_after() const;

public:
    MsgPrinterSurrounding(const string &);
    MsgPrinterSurrounding(const string &, const char *, const char *);
    MsgPrinterSurrounding(const MsgPrinterSurrounding &);
    ~MsgPrinterSurrounding();

    MsgPrinterSurrounding & operator=(const MsgPrinterSurrounding & ); 
    void print() const;
    const char* get_after() const;
    const char* get_before() const;
};

//********************************** inlines MsgPrinterSurrounding Class **************************************//

//*************************************************************************************************************//
//*************************************************************************************************************//

#endif

//************************************* inlines MsgPrinter Class **********************************************//

inline void MsgPrinter::print() const
{
    cout << "Message: " << this->message << endl;
}

inline const string MsgPrinter::get_message() const
{
    return this->message;
}

//********************************** inlines MsgPrinterSurrounding Class **************************************//

inline void MsgPrinterSurrounding::print_before() const
{
    this->m_before == NULL ? cout << "NULL" << endl : cout << this->m_before << endl;
}
inline void MsgPrinterSurrounding::print_after() const
{
    this->m_after == NULL ? cout << "NULL" << endl : cout << this->m_after << endl;
}
inline const char * MsgPrinterSurrounding::get_after() const
{
    return this->m_after;
}
inline const char* MsgPrinterSurrounding::get_before() const
{
    return this->m_before;
}

inline void MsgPrinter::set_message(const string & msg)
{
    this->message=msg;
}
