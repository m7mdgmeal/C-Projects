#ifndef MY_TIME_H
#define MY_TIME_H

#define MAX_MIN_SEC 59 // max value of minutes and seconds
#define ZERO 0
#define MAX_HOURS 100000 // max value of hours

typedef enum
{
    MASK_MIN_SEC = 63,
    MASK_HOUR = 131071
} mask_bits; // An enum named mask_bits, its hold a bit mask for hour,second and mintues

typedef enum
{
    SECONDS,
    MINUTES,
    HOURS
} time_units; // define the time unit (seconds, minutes,hours)

#include <iostream>  // cin/cout operation
#include <stdio.h>   // in order to use sprintf
#include <cstring>   // to use a data-type string
using namespace std; // in order to prevent from using "std::" all the time

class Time
{
private:
    //************************* privated members ***************************//

    unsigned short int seconds : 6; // declare a secounds with 6 bits.(0 to 63)
    unsigned short int minutes : 6; // declare a minutes with 6 bits. (0 to 63)
    unsigned int hours : 17;        // declare a hours with 17 bits.  (0 to 131071)

    //**********************************************************************//

    //******************* private static const members *********************//
    static const unsigned short int SIXTY = 60;
    static const unsigned short int TEN = 10;
    static const unsigned short int ONE_DAY = 24;
    static char day_dilimter;
    static char time_dilimter;

    //************************** private methods ***************************//

    unsigned int valid(unsigned int vale, time_units t_unit); // return the entered value if its was ligal depends in time units

    //***********************************************************************//
public:
    //************************** intilisation *******************************//

    Time();                                                                // defult ctor
    Time(unsigned int hour, unsigned int minute, unsigned int second = 0); // a cnostructor that gets 3 elements (seconds are 0 by defult),in case of Invalid input -> throw anvalied excp
    Time(unsigned long);                                                   // a ctor that gets a secound number and gets the hour,mintues , secounds
    Time(const Time &time);                                                // copy constructor
    
    ~Time();                                                               // destructor

    //**************************************************************************//

    //*************************** getters and setters **************************//(inline methods)

    unsigned short int get_seconds() const; // getting the seconds
    unsigned short int get_minutes() const; // getting the minutes
    unsigned int get_hours() const;         // getting the hours
    void set_seconds(int);                  // setting legal secounds , in case of invalid input ->throw an anvalid input exception
    void set_minutes(int);                  // setting legal minutes , in case of invalid input ->throw an anvalid input exception
    void set_hours(int);                    // setting legal hours , in case of invalid input ->throw an anvalid input exception

    //***************************************************************************//

    //******************************** class methods ****************************//
    string get_as_str(bool) const;
    unsigned long get_time_by_seconds() const;
    static void modify_dilimters(const char day,const char time);
    //********************************* operators *******************************//

    Time operator+(const Time &time) const;
    Time &operator+=(const Time &time);
    Time &operator+=(const unsigned long seconds);
    const bool operator<(const Time &time) const;
    const bool operator>(const Time &time) const;
    const bool operator==(const Time &time) const;
    const bool operator!=(const Time &time) const;
    const bool operator<=(const Time &time) const;
    const bool operator>=(const Time &time) const;
    friend ostream& operator<<(ostream& os, const Time& time);

};

#endif
// *******************************************************************************//
// *******************************************************************************//
//******************************* inline functions *******************************//

//******************************* getters ***************************************//
inline unsigned short int Time::get_seconds() const
{
    return this->seconds;
}

inline unsigned short int Time::get_minutes() const
{
    return this->minutes;
}

inline unsigned int Time::get_hours() const
{
    return this->hours;
}
//******************************* setters ***************************************//

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
//*********************************** class methods ********************************************//
inline unsigned long Time::get_time_by_seconds() const
{
    return this->seconds + SIXTY * this->minutes + this->hours * SIXTY * SIXTY;
}

// *********************************************************************************************//
// *********************************************************************************************//
// *********************************** operators ***********************************************//

inline Time &Time::operator+=(const Time &time)
{
    return (*this = (*this + time));
}

inline Time &Time::operator+=(const unsigned long seconds)
{
    return (*this = (*this + seconds));
}

inline Time Time::operator+(const Time &time1) const
{
    return Time(this->get_time_by_seconds() + time1.get_time_by_seconds());
}

inline const bool Time::operator==(const Time &time) const
{
    return ((this->get_hours() == time.get_hours()) && (this->get_minutes() == time.get_minutes()) && (this->get_seconds() == time.get_seconds()));
}

inline const bool Time::operator!=(const Time &time) const
{
    return !(*this == time);
}

inline const bool Time::operator<(const Time &time) const
{
    return (this->get_time_by_seconds() < time.get_time_by_seconds());
}

inline const bool Time::operator>(const Time &time) const
{
    return (this->get_time_by_seconds() > time.get_time_by_seconds());
}

inline const bool Time::operator>=(const Time &time) const
{
    return (*this > time) || (*this == time);
}

inline const bool Time::operator<=(const Time &time) const
{
    return (*this < time) || (*this == time);
}
//********************************* global functions *****************************//

void print(const Time &other);
Time operator+(const unsigned long, const Time &time);
