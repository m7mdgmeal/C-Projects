#include "my_time.h"

int main()
{
    try
    {
        cout<<endl<<endl;
        
        Time time1(24,10,10);
        Time time2(3659);
        
        Time copy=time1;
        
        time1.modify_dilimters('.',':');

        cout<<"Time1 object: "<<time1<<"   "<<time1.get_as_str(false)<<endl;
        cout<<"Time2 object: "<<time2<<"   "<<time2.get_as_str(false)<<endl;
        cout<<"Copy object: "<<copy<<"    "<<copy.get_as_str(false)<<endl;

        if(copy == time1)
            cout<<"time1 == copy"<<endl;
        else
            cout<<"time1 != copy"<<endl;

        if(copy != time2)
            cout<<"time2 != copy"<<endl;
        else
            cout<<"time2 == copy"<<endl;

        if(copy <= time1)
            cout<<"copy <= time1"<<endl;
        else
            cout<<"copy > time1"<<endl;

        if(copy > time2)
            cout<<"copy > time2 "<<endl;
        else
            cout<<"copy <= time2"<<endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}