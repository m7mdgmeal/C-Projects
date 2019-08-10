#include "my_timer.h"

// ctor that takes 2 arguments , and initialize them to target object and pprint pinter , and initialize clock to 00:00:00
Timer::Timer(const Time &tr, MsgPrinter *msg) : target(tr), clock(0), pprint(msg)
{

}

// dtor that prints the end of the Timer with the message
Timer::~Timer()
{
    cout << "End of MsgPrinterMultipleSurrounding: ";
    this->pprint->print();

}


// a private function that incrased the clock by:
/*
    * if time_type(time unit) is empty(did not insert time_unit) --> increae the clock by number of seconds(value)
    * if time_type(time unit) is minutes(with all the idintifiers of minutes) --> increase the clock by number of minutes(value is the number)
    * if time_type(time unit) is houes (with all the identifires of hours) --> increase the clock by number of hours(value is the number)
    * in other case throw and exception of Invalid_argument
*/
void Timer::increse_clock(unsigned int value, string time_type)
{
    if (time_type.empty())
        this->clock += value;
    else
    {
        if (!time_type.compare("m") || !time_type.compare("M") || !time_type.compare("Minute") || !time_type.compare("minute") || !time_type.compare("min") ||
         !time_type.compare("Min"))
            this->clock += ONE_MINUTES*value;
        else if (!time_type.compare("H") || !time_type.compare("h") || !time_type.compare("Hour") || !time_type.compare("hour"))
            this->clock += ONE_HOUR*value;
        else
            throw invalid_argument("Invalid Argument!!");
    }
}