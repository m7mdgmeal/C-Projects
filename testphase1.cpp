#include "my_time.h"

int main()
{
    try
    {
        cout<<endl<<endl;
        
        Time time1(24,10,10);
        Time time2(26,56,49);
        
        cout<<time1.get_as_str(false)<<endl;
        cout<<time1.get_as_str(true)<<endl;
        cout<<time1.get_time_by_seconds()<<endl<<endl;

        cout<<time2.get_as_str(false)<<endl;
        cout<<time2.get_as_str(true)<<endl;
        cout<<time2.get_time_by_seconds()<<endl;


        cout<<endl<<endl;
        cout<<"Test operator +"<<endl;
        
        Time copy=time1;
        
        cout<<copy.get_as_str(false)<<endl;
        cout<<copy.get_as_str(true)<<endl;
        cout<<copy.get_time_by_seconds()<<endl<<endl;

        copy+=time2;
        
        cout<<copy.get_as_str(false)<<endl;
        cout<<copy.get_as_str(true)<<endl;
        cout<<copy.get_time_by_seconds()<<endl<<endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}