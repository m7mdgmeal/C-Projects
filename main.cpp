#include "my_timer.h"
#include <unistd.h>
#include "testphase2.cpp"
int main()
{
    //run_timer_1();
    //run_timer_2();

    cout << "*****************************************" << endl;
    cout << "*****************************************" << endl;
    string msg = string("K_Base");
    string msg1= string("L_Base");

    MsgPrinterSurrounding k(msg,"k_before" ,"K_after");
    MsgPrinterSurrounding l(msg1,"l_before" ,"l_after");

    cout << "*****************************************" << endl;
    cout << "************* k object ******************" << endl;
    cout << "*****************************************" << endl;
    k.print();
    cout << "*****************************************" << endl;
    cout << "************* l object ******************" << endl;
    cout << "*****************************************" << endl;
    l.print();

    k=l;
    cout << "*****************************************" << endl;
    cout << "************* k object ******************" << endl;
    cout << "*****************************************" << endl;
    k.print();
    cout << "*****************************************" << endl;
    return 0;
}
