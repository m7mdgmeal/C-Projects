#ifndef MSG_PRINTER_H
#define MSG_PRINTER_H

#include <iostream>
#include <string>
#include <new>         
#include <string.h>

using namespace std;

//***********************************************************************************//
//************************* MsgPrinter Class ****************************************//
//***********************************************************************************//

class MsgPrinter
{

private:
    //**************************** private members **********************************//

    string message; // a const string that holds the message string

public:
    //**************************** public methods ***********************************//

    //*************************** Intialization methods *****************************//
    MsgPrinter(const string &message); // ctor that takes string as a string object
    MsgPrinter(const char *message);   // ctor that takes string as a char * object
    MsgPrinter(const MsgPrinter &);    // c.ctor
    //**************************** destruction method *******************************//
    virtual ~MsgPrinter();             // dtor
    //**************************** getters & setters ********************************//
    const string get_message() const;  //gets the message as a string
    void set_message(const string &);  // set string to message 

    //****************************** class methods **********************************//
    virtual void print() const; // virtual print function , print the message
};

//*************************************************************************************************************//
//*************************************************************************************************************//

//*************************************************************************************************************//
//************************************** MsgPrinterSurrounding Class ******************************************//
//*************************************************************************************************************//
// inherte from MsgPrinter a public inhertence
class MsgPrinterSurrounding : public MsgPrinter
{
private:

    //**************************** private members **********************************//

    char *m_before;                                                     // a string that have the before message
    char *m_after;                                                      // a string that have the after message
    void clone_msg(const char *base_msg, char **required_msg);          // private funtion that alocate and clone strings

    //*******************************************************************************//

protected:
    virtual void print_before() const;
    void print_after() const;

public:
    //**************************** public methods ***********************************//

    //*************************** Intialization methods *****************************//
    MsgPrinterSurrounding(const string &);                              // ctor with 1 arguments, that iniatilaze the Base class with this argument 
                                                                        //and nulls the before and after

    MsgPrinterSurrounding(const string &, const char *, const char *);  // ctor with 3 args, that intialize the Base class , before and after
    MsgPrinterSurrounding(const MsgPrinterSurrounding &);               // c.ctor that intialize the Base class , before and after
    ~MsgPrinterSurrounding();    
                                                                        // dtor , that deletes before and after and destruct the object.
    
    //****************************** operators *************************************//
    MsgPrinterSurrounding &operator=(const MsgPrinterSurrounding &);


    //****************************** getters ***************************************//

    const char *get_after() const;
    const char *get_before() const;

    //****************************** override **************************************//

    void print() const;


};

#endif
//*************************************************************************************************************//
//*************************************************************************************************************//
//*************************************************************************************************************//


//*************************************************************************************************************//
//************************************* inlines MsgPrinter Class **********************************************//
//*************************************************************************************************************//

inline void MsgPrinter::print() const                                   // prints the message 
{
    cout << "Message: " << this->message << endl;
}

inline const string MsgPrinter::get_message() const                     // gets the message
{
    return this->message;
}

inline void MsgPrinter::set_message(const string &msg)                   // set the message with msg object
{
    this->message = msg;
}

//*************************************************************************************************************//
//********************************** inlines MsgPrinterSurrounding Class **************************************//
//*************************************************************************************************************//

inline void MsgPrinterSurrounding::print_before() const                 // prints the before string , if its null --> prints null
{
    this->m_before == NULL ? cout << "NULL" << endl : cout << this->m_before << endl;
}

inline void MsgPrinterSurrounding::print_after() const                  // prints the after string , if its null --> prints null
{
    this->m_after == NULL ? cout << "NULL" << endl : cout << this->m_after << endl;
}

inline const char *MsgPrinterSurrounding::get_after() const             // gets the after string(message)
{
    return this->m_after;
}

inline const char *MsgPrinterSurrounding::get_before() const            //gets the before string(message)
{
    return this->m_before;
}