#ifndef MY_TIMER_H
#define MY_TIMER_H

#define ONE_SECOUND 1             // define 1 secound as 1
#define ONE_MINUTES 60            // define a minutes as 60 seconds
#define ONE_HOUR 3600             // define a hour as 3600 seconds

#include "msg_printer.h"
#include "my_time.h"

class Timer
{


//***************************************************************************//
//**************************** private area *********************************//
private:

    //***********************************************************************//
    //************************ private members ******************************//
    Time target;                                                 // a Time object , that hold the alarm time
    Time clock;                                                  // a Time object , that hold a time counter (initialize from 0 !)
    MsgPrinter *pprint;                                          // member of class that is a pointer to object from MspPrint->it save to message of alarm

    //***********************************************************************//
    //************************* private methods *****************************//
    bool is_done()const;                                        // privaate method that return true if the counter(clock) is reached the target time
    void increse_clock(unsigned int value, string time_type); // incresing the clock by  minutes , hours, seconds ,depents in value and time_unit

//***************************************************************************//
//**************************** public area **********************************//

public:

    //*************************************************************************//
    //************************* initialization ********************************//
    // ctor that takes 2 arguments, the first argument to initialize the target and the other one to initialize the the pointer to pprint
    Timer(const Time &tr, MsgPrinter *msg);
    // detor
    ~Timer();
    //*************************************************************************//
    //************************* class methods *********************************//
    void tick();                                                  // increasing clock by 1 seound
    void tick(unsigned int seconds);                              // increasing clock by number of seconds  
    void tick(const string time, unsigned int value = 1);         // increasing clock by (1 minute or more , 1 hour or more)
                                                                  // by defult second is 1 , because incrase clock have a multiplay operation 

    //*************************************************************************//
    //***************************** getters ***********************************//
    const Time &get_clock() const;                                // gets the clock
};
inline bool Timer::is_done()const
{
    return (this->clock.get_time_by_seconds() >= this->target.get_time_by_seconds());      // return true of clock is equal , bigger than the target
}
inline void Timer::tick()
{
    if(is_done())                                                  // if clock reached to target --> prints the message of alarm 
     pprint->print(); 
    increse_clock(ONE_SECOUND, string(""));                        // if not increase the clock by 1 second

}
inline void Timer::tick(unsigned int seconds)                                               
{
    if (is_done())                                                 // if clock reached to target --> prints the message of alarm 
        pprint->print();
    increse_clock(seconds, string(""));                            // if not increase the clock by number of seconds

}
inline void Timer::tick(const string time, unsigned int value) 
{
    if (is_done())                                                 // if clock reached to target --> prints the message of alarm 
        pprint->print();
    increse_clock(value, time);                                    // increase the clock by number of mintues or number of hours(depends in time string and value)

}

inline const Time &Timer::get_clock() const                        // getting the clock as a cont object
{
    return this->clock;
}

#endif