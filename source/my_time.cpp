#include "my_time.h"

//********************************************************************************************//
//********************************************************************************************//
//********************************* inilization decleration ********************************//

// intilize statics
char Time::day_dilimter = '.';
char Time::time_dilimter = ':';

// defult constructor
Time::Time() : seconds_(ZERO & MASK_MIN_SEC),
               minutes_(ZERO & MASK_MIN_SEC),
               hours_(ZERO & MASK_HOUR)
{
}
// ctor with 3 arguments //

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) : seconds_(valid(second, SECONDS) & MASK_MIN_SEC),
                                                                          minutes_(valid(minute, MINUTES) & MASK_MIN_SEC),
                                                                          hours_(valid(hour, HOURS) & MASK_HOUR)
{
}
// ctor with 1 arguments //
Time::Time(unsigned long secounds_number) : seconds_((secounds_number % SIXTY) & MASK_MIN_SEC),
                                            minutes_(((secounds_number / SIXTY) % SIXTY) & MASK_MIN_SEC),
                                            hours_((secounds_number / (SIXTY * SIXTY)) & MASK_HOUR)
{
}

// copy constructor //
Time::Time(const Time &time) : seconds_(time.get_seconds() & MASK_MIN_SEC),
                               minutes_(time.get_minutes() & MASK_MIN_SEC),
                               hours_(time.get_hours() & MASK_HOUR)
{
    cout<<"I am a copy ctor"<<endl;
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
    if (t_unit == MINUTES)
        return (value < ZERO || value > MAX_MIN_SEC) ? throw invalid_argument("mintes max value is 59!!") : value;
    else if (t_unit == SECONDS)
        return (value < ZERO || value > MAX_MIN_SEC) ? throw invalid_argument("seconds max vale is 59!!") : value;
    else
        return (value < ZERO || value > MAX_HOURS) ? throw invalid_argument("hours max vale is 100,000!!") : value;
}

void Time::add_seconds(unsigned long seconds)
{
    unsigned long secounds_number = this->get_time_by_seconds() + seconds;
    this->seconds_ = (secounds_number % SIXTY) & MASK_MIN_SEC;
    this->minutes_ = ((secounds_number / SIXTY) % SIXTY) & MASK_MIN_SEC;
    this->hours_ = (secounds_number / (SIXTY * SIXTY)) & MASK_HOUR;
}
//*********************************************************************************************//
//*********************************************************************************************//
//*************************** class mehods declerations ***************************************//

string Time::get_as_str(bool is_using_days) const
{
    char time_display[TEN + TEN];
    if (is_using_days == true)
    {
        this->hours_ % ONE_DAY < TEN ? sprintf(time_display, "%d%c0%d%c", this->hours_ / ONE_DAY, this->day_dilimter, this->hours_ % ONE_DAY, this->time_dilimter)
                                     : sprintf(time_display, "%d%c%d%c", this->hours_ / ONE_DAY, this->day_dilimter, this->hours_ % ONE_DAY, this->time_dilimter);
    }
    else
    {
        this->hours_ < TEN ? sprintf(time_display, "0%d%c", this->hours_, this->time_dilimter)
                           : sprintf(time_display, "%d%c", this->hours_, this->time_dilimter);
    }
    this->minutes_ < TEN ? sprintf(time_display, "%s0%d%c", time_display, this->minutes_, this->time_dilimter)
                         : sprintf(time_display, "%s%d%c", time_display, this->minutes_, this->time_dilimter);
    this->seconds_ < TEN ? sprintf(time_display, "%s0%d", time_display, this->seconds_)
                         : sprintf(time_display, "%s%d", time_display, this->seconds_);

    return string(time_display);
}

// *********************************************************************************************//
// *********************************************************************************************//
// *********************************** operators ***********************************************//

Time operator+(const unsigned long seconds, const Time &time)                 // friend operator 
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