#include "my_time.h"

int main()
{
    try
    {
        Time time1(24,10,10);
        Time time2(9999);

        cout<<time1.get_as_str(false)<<endl;
        cout<<time1.get_as_str(true)<<endl;
        cout<<time1.get_time_by_seconds()<<endl<<endl;
        cout<<time2.get_as_str(false)<<endl;
        cout<<time2.get_as_str(true)<<endl;
        cout<<time2.get_time_by_seconds()<<endl;


        cout<<endl<<endl;
        print(time1);
    
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}