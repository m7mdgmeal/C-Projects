#include "msg_printer.h"

MsgPrinter::MsgPrinter(const string message) : message(message)
{
}

MsgPrinter::MsgPrinter(const char *message) : message(message)
{
}

MsgPrinter::~MsgPrinter()
{
    cout << "End of MsgPrinter: " <<this->message<< endl;
}

void MsgPrinter::print()
{
    cout<<"Message: "<<this->message<<endl;
}
