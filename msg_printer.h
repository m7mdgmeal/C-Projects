#ifndef MSG_PRINTER_H
#define MSG_PRINTER_H

#include <iostream>
#include <string>

using namespace std;

class MsgPrinter
{
private:
    const string message;             // a const string that holds the message string
public:
    MsgPrinter(const string message); // ctor that takes string as a string object
    MsgPrinter(const char *message);  // ctor that takes string as a char * object
    ~MsgPrinter();                    // dtor

    virtual void print();             // virtual print function , print the message
};

#endif