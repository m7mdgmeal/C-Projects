#include "my_time.h"

//********************************************************************************************//
//********************************************************************************************//
//********************************* inilization decleration ********************************//

// intilize statics
char Time::day_dilimter = '.';
char Time::time_dilimter = ':';

// defult constructor
Time::Time() : seconds(0 & MASK_MIN_SEC),
               minutes(0 & MASK_MIN_SEC),
               hours(0 & MASK_HOUR)
{
}
// ctor with 3 arguments //

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) : seconds(valid(second, SECONDS) & MASK_MIN_SEC),
                                                                          minutes(valid(minute, MINUTES) & MASK_MIN_SEC),
                                                                          hours(valid(hour, HOURS) & MASK_HOUR)
{
}
// ctor with 1 arguments //
Time::Time(unsigned long secounds_number) : seconds((secounds_number % SIXTY) & MASK_MIN_SEC),
                                            minutes(((secounds_number / SIXTY) % SIXTY) & MASK_MIN_SEC),
                                            hours((secounds_number / (SIXTY * SIXTY)) & MASK_HOUR)
{
}

// copy constructor //
Time::Time(const Time &time) : seconds(time.get_seconds() & MASK_MIN_SEC),
                               minutes(time.get_minutes() & MASK_MIN_SEC),
                               hours(time.get_hours() & MASK_HOUR)
{
}

// destractor //
Time::~Time()
{
}

//********************************************************************************************//
//********************************************************************************************//
//********************************************************************************************//
//******************************* private method decleartions ********************************//

unsigned int Time::valid(unsigned int value, time_units t_unit)
{
    string error_msg;
    if (t_unit == MINUTES)
        return (value < ZERO || value > MAX_MIN_SEC) ? throw invalid_argument("mintes max value is 59!!") : value;
    else if (t_unit == SECONDS)
        return (value < ZERO || value > MAX_MIN_SEC) ? throw invalid_argument("seconds max vale is 59!!") : value;
    else
        return (value < ZERO || value > MAX_HOURS) ? throw invalid_argument("hours max vale is 100,000!!") : value;
}

//*********************************************************************************************//
//*********************************************************************************************//
//*************************** class mehods declerations ***************************************//

string Time::get_as_str(bool is_using_days) const
{
    char time_display[TEN + TEN];
    if (is_using_days == true)
    {
        this->hours % ONE_DAY < TEN ? sprintf(time_display, "%d%c0%d%c", this->hours / ONE_DAY, this->day_dilimter, this->hours % ONE_DAY, this->time_dilimter)
                                    : sprintf(time_display, "%d%c%d%c", this->hours / ONE_DAY, this->day_dilimter, this->hours % ONE_DAY, this->time_dilimter);
    }
    else
    {
        this->hours < TEN ? sprintf(time_display, "0%d%c", this->hours, this->time_dilimter)
                          : sprintf(time_display, "%d%c", this->hours, this->time_dilimter);
    }
    this->minutes < TEN ? sprintf(time_display, "%s0%d%c", time_display, this->minutes, this->time_dilimter)
                        : sprintf(time_display, "%s%d%c", time_display, this->minutes, this->time_dilimter);
    this->seconds < TEN ? sprintf(time_display, "%s0%d", time_display, this->seconds)
                        : sprintf(time_display, "%s%d", time_display, this->seconds);

    return string(time_display);
}

// *********************************************************************************************//
// *********************************************************************************************//
// *********************************** operators ***********************************************//

//************************* global operator +  for constant + time *****************************//
Time operator+(const unsigned long seconds, const Time &time)
{
    return time + seconds;
}

ostream &operator<<(ostream &os, const Time &time)
{
    os << time.get_as_str(true);
    return os;
}

// *********************************************************************************************//
// *********************************************************************************************//
// ************************************* global functions **************************************//
void print(const Time &other)
{
    cout << other.get_hours() / 24 << "/" << other.get_hours() << "/" << other.get_minutes() << "/" << other.get_minutes() << endl;
}
