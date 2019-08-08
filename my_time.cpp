#include "my_time.h"

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) : seconds(valid(second, SECONDS) & MASK_MIN_SEC),
                                                                          minutes(valid(minute, MINUTES) & MASK_MIN_SEC),
                                                                          hours(valid(hour, HOURS) & MASK_HOUR)
{
}

Time::Time(unsigned int secounds_number) : seconds((secounds_number % SIXTY) & MASK_MIN_SEC),
                                           minutes(((secounds_number / SIXTY) % SIXTY) & MASK_MIN_SEC),
                                           hours((secounds_number / (SIXTY*SIXTY)) & MASK_HOUR)
{
}

Time::~Time()
{
    cout << "I am a destructor of Timer" << endl;
}

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

string Time::get_as_str(bool is_using_days)const
{
    char time_display[TEN+TEN];
    if (is_using_days == true)
    {
        this->hours%ONE_DAY < TEN ? sprintf(time_display, "%d.0%d:",this->hours/ONE_DAY,this->hours%ONE_DAY) : sprintf(time_display, "%d.%d:", this->hours/ONE_DAY,this->hours%ONE_DAY);
    }
    else
        this->hours < TEN ? sprintf(time_display, "0%d:", this->hours) : sprintf(time_display, "%d:",this->hours);
    this->minutes < TEN ? sprintf(time_display, "%s0%d:", time_display, this->minutes) : sprintf(time_display, "%s%d:", time_display, this->minutes);
    this->seconds < TEN ? sprintf(time_display, "%s0%d", time_display, this->seconds) : sprintf(time_display, "%s%d", time_display, this->seconds);
    return string(time_display);
}

void print(const Time & other)
{
    cout<<other.get_hours()/24<<"/"<<other.get_hours()<<"/"<<other.get_minutes()<<"/"<<other.get_minutes()<<endl;
}