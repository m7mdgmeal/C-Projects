#ifndef MSG_PRINTER_H
#define MSG_PRINTER_H

#include<iostream>
#include<string>

using namespace std;

class MsgPrinter
{
private:
    const string message;
public:
    MsgPrinter(const string message);
    MsgPrinter(const char * message);
    ~MsgPrinter();

    virtual void print();
};


#endif