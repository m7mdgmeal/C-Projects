#ifndef MSG_PRINTER_H
#define MSG_PRINTER_H

#include <iostream>
#include <string>
#include <new>
#include <string.h>
#include <stdlib.h>

using namespace std;

//***********************************************************************************//
//***********************************************************************************//
//************************* MsgPrinter Class ****************************************//
//***********************************************************************************//
//***********************************************************************************//

class MsgPrinter
{

private:
    //**************************** private members **********************************//

    string message; // a const string that holds the message string

public:
    //**************************** public methods ***********************************//

    //*************************** Intialization methods *****************************//
    MsgPrinter();
    MsgPrinter(const string &message); // ctor that takes string as a string object
    MsgPrinter(const MsgPrinter &);    // c.ctor
    //**************************** destruction method *******************************//
    virtual ~MsgPrinter(); // dtor
    //**************************** getters & setters ********************************//
    const string get_message() const; //gets the message as a string
    void set_message(const string &); // set string to message

    //****************************** class methods **********************************//
    virtual void print() const; // virtual print function , print the message
};



//*************************************************************************************************************//
//*************************************************************************************************************//

//*************************************************************************************************************//
//*************************************************************************************************************//
//************************************** MsgPrinterSurrounding Class ******************************************//
//*************************************************************************************************************//
//*************************************************************************************************************//

// inherte from MsgPrinter a public inhertence

class MsgPrinterSurrounding : public MsgPrinter
{
private:

    //**************************** private members ***********************************/ /
    char *m_before;                                            // a string that have the before message
    char *m_after;                                             // a string that have the after message
    void clone_msg(const char *base_msg, char **required_msg); // private funtion that alocate and clone strings

    //*******************************************************************************//

protected:

    //**************************** protected methods **********************************//
    virtual void print_before() const;
    void print_after() const;

public:
    //**************************** public methods ***********************************//

    //*************************** Intialization methods *****************************//
    MsgPrinterSurrounding(const string &); // ctor with 1 arguments, that iniatilaze the Base class with this argument
                                           //and nulls the before and after

    MsgPrinterSurrounding(const string &, const char *, const char *); // ctor with 3 args, that intialize the Base class , before and after
    MsgPrinterSurrounding(const MsgPrinterSurrounding &);              // c.ctor that intialize the Base class , before and after
    virtual ~MsgPrinterSurrounding();                                          // dtor , that deletes before and after and destruct the object.

    //****************************** operators *************************************//
    MsgPrinterSurrounding &operator=(const MsgPrinterSurrounding &); // operator assigment that clone the rigth object to the left one.

    //****************************** getters ***************************************//

    const char *get_after() const;  // getter for the before string
    const char *get_before() const; // getter for the after string

    //****************************** override **************************************//

    void print() const; // an override print function
};
//***********************************************************************************//
//***********************************************************************************//

//***********************************************************************************//
//***********************************************************************************//
//********************** MsgPrinterMultipleSurrounding Class ************************//
//***********************************************************************************//
//***********************************************************************************//

class MsgPrinterMultipleSurrounding :public MsgPrinterSurrounding
{
private:
    unsigned char m_times;

public:

    MsgPrinterMultipleSurrounding(const string &, unsigned char = 2); // ctor with 2 or 1 arguments, that iniatilaze the Base class with this argument
                                                                      //and nulls the before and after

    MsgPrinterMultipleSurrounding(const string &, const char *, const char *, unsigned char = 2); // ctor with 4 or 3args, that intialize the Base class with
                                                                                                  // the first 3 args , the 4th arg is by defult 2, that init m_times
    MsgPrinterMultipleSurrounding(const MsgPrinterMultipleSurrounding &);                         // c.ctor that intialize the Base class , and m_times
    virtual ~MsgPrinterMultipleSurrounding();                                                             // dtor.

    void set_times(const unsigned char);
    const unsigned char get_times() const;

    void print_before()const;
    void print_after()const;
};

//***********************************************************************************//
//***********************************************************************************//

#endif
//*************************************************************************************************************//
//*************************************************************************************************************//
//*************************************************************************************************************//

//*************************************************************************************************************//
//************************************* inlines MsgPrinter Class **********************************************//
//*************************************************************************************************************//


inline const string MsgPrinter::get_message() const // gets the message
{
    return this->message;
}

inline void MsgPrinter::set_message(const string &msg) // set the message with msg object
{
    this->message = msg;
}

//*************************************************************************************************************//
//********************************** inlines MsgPrinterSurrounding Class **************************************//
//*************************************************************************************************************//


inline void MsgPrinterSurrounding::print_after() const // prints the after string , if its null --> prints null
{
    this->m_after == NULL ? cout << "NULL" << endl : cout << this->m_after << endl;
}

inline const char *MsgPrinterSurrounding::get_after() const // gets the after string(message)
{
    return this->m_after;
}

inline const char *MsgPrinterSurrounding::get_before() const //gets the before string(message)
{
    return this->m_before;
}

//*************************************************************************************************************//
//****************************** inlines MsgPrinterMultipleSurrounding Class **********************************//
//*************************************************************************************************************//


inline void MsgPrinterMultipleSurrounding::set_times(const unsigned char times)  // set m_times to times 
{
    this->m_times=times;
}
inline const unsigned char MsgPrinterMultipleSurrounding::get_times() const      // gets m_times as a const
{
    return this->m_times;
}


