#ifndef MY_TIMER_H
#define MY_TIMER_H

#define ONE_SECOUND 1
#define ONE_MINUTES 60
#define ONE_HOUR 3600 
#include "msg_printer.h"
#include "my_time.h"

using namespace std;
class Timer
{
private:

    Time target;
    Time clock;                                                            
    MsgPrinter *pprint;                                                    // member of class that is a pointer to object from MspPrint->it save to message of alarm 
    bool is_done();
    void increse_clock(unsigned int secdons,string time_type="");          // incresing the clock by 1 minutes , 1 hour, 1 second , number of seconds of mix
                                                                           // by the time_type
public:

    Timer(const Time &tr, MsgPrinter *msg);
    ~Timer();
    void tick();
    void tick(unsigned int seconds);
    void tick(const string time, unsigned int seconds =0);

};
inline bool Timer::is_done()
{
    return (this->clock.get_time_by_seconds() >= this->target.get_time_by_seconds());
}
inline void Timer::tick()
{
    is_done()? pprint->print():increse_clock(ONE_SECOUND);
}
inline void Timer::tick(unsigned int seconds)
{
    is_done() ? pprint->print() : increse_clock(seconds);
}
inline void Timer::tick(const string time,unsigned int seconds)
{
    is_done() ? pprint->print():increse_clock(seconds,time);
}

#endif