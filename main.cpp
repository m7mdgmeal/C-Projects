#include "my_timer.h"
#include <unistd.h>
#include "testphase2.cpp"
int main()
{
  //  run_timer_1();
   // run_timer_2();

    cout<<"*****************************************"<<endl;
    cout<<"*****************************************"<<endl;
    cout<<"*****************************************"<<endl;
    string msg=string("Base messagme");
    MsgPrinterSurrounding(msg,"Before message","After Msg");
    return 0;
}

