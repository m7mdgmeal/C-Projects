#include "my_timer.h"

Timer::Timer(const Time &tr, MsgPrinter *msg) : target(tr), clock(0), pprint(msg)
{
    cout << this->target << endl;
    cout << this->clock << endl;
    pprint->print();
}

Timer::~Timer()
{
    cout << "End of MsgPrinterMultipleSurrounding: ";
    this->pprint->print();

}

void Timer::increse_clock(unsigned int seconds, string time_type)
{
    if (time_type.empty())
        this->clock += seconds;
    else
    {
        if (!time_type.compare("m") || !time_type.compare("M") || !time_type.compare("Minute") || !time_type.compare("minute") || !time_type.compare("min") ||
         !time_type.compare("Min"))
            this->clock += ONE_MINUTES*seconds;
        else if (!time_type.compare("H") || !time_type.compare("h") || !time_type.compare("Hour") || !time_type.compare("hour"))
            this->clock += ONE_HOUR*seconds;
        else
            throw invalid_argument("Invalid Argument!!");
    }
}