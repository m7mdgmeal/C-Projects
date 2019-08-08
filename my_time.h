#ifndef MY_TIME_H
#define MY_TIME_H

#define MAX_MIN_SEC 59
#define ZERO 0
#define MAX_HOURS 100000

typedef enum
{
    MASK_MIN_SEC = 63,
    MASK_HOUR = 131071
} mask_bits;

typedef enum
{
    SECONDS,
    MINUTES,
    HOURS
} time_units;

#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;

class Time
{
private:
    //************************* privated members ***************************//

    unsigned short int seconds : 6;  // declare a secounds with 6 bits.(0 to 63)
    unsigned short int minutes : 6;  // declare a minutes with 6 bits. (0 to 63)
    unsigned int hours : 17;         // declare a hours with 17 bits.  (0 to 131071) 

    //**********************************************************************//

    //******************* private static const members *********************//
    static const unsigned short int SIXTY= 60;
    static const unsigned short int TEN = 10 ;
    static const unsigned short int ONE_DAY = 24;

    //************************** private methods ***************************//

    unsigned int valid(unsigned int vale, time_units t_unit);               // return the entered value if its was ligal depends in time units

    //***********************************************************************//
public:

    //************************** intilisation *******************************//
    
    Time(unsigned int hour, unsigned int minute, unsigned int second = 0);  // a cnostructor that gets 3 elements (seconds are 0 by defult),in case of Invalid input -> throw anvalied excp
    Time(unsigned int );                                                    // a ctor that gets a secound number and gets the hour,mintues , secounds
    ~Time();                                                                // destructor

    //**************************************************************************//

    //*************************** getters and setters **************************//(inline methods)
    
    unsigned short int get_seconds()const;                                       // getting the seconds
    unsigned short int get_minutes()const;                                       // getting the minutes
    unsigned int get_hours()const;                                               // getting the hours
    void set_seconds(int);                                                  // setting legal secounds , in case of invalid input ->throw an anvalid input exception                        
    void set_minutes(int);                                                  // setting legal minutes , in case of invalid input ->throw an anvalid input exception                                                
    void set_hours(int);                                                    // setting legal hours , in case of invalid input ->throw an anvalid input exception                                                


    //***************************************************************************//


    //******************************** class methods ***********************************//
    string get_as_str(bool)const;
    int get_time_by_seconds();
};

#endif




//******************************* inline functions ****************************//


inline unsigned short int Time::get_seconds()const
{
    return this->seconds;
}

inline unsigned short int Time::get_minutes()const
{
    return this->minutes;
}

inline unsigned int Time::get_hours()const
{
    return this->hours;
}

inline void Time::set_seconds(int seconds)
{
    this->seconds = (seconds < 0 || seconds > MAX_MIN_SEC) ? throw invalid_argument("secound max is 59") : seconds & MASK_MIN_SEC;
}

inline void Time::set_minutes(int minutes)
{
    this->minutes = (minutes < 0 || minutes > MAX_MIN_SEC) ? throw invalid_argument("minutes max is 59") : minutes & MASK_MIN_SEC;
}

inline void Time::set_hours(int hours)
{
    this->hours = (hours < 0 || hours > MAX_MIN_SEC) ? throw invalid_argument("hours max is 100,000") : hours & MASK_HOUR;
}

inline int Time::get_time_by_seconds()
{
    return this->seconds+60*this->minutes+this->hours*60*60;
}


void print( const Time & other);