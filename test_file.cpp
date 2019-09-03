#include "my_timer.h"
#include "test_file.h"
#include <unistd.h>
#include <list>
#include <iterator>

void print_design_iterator(int i)
{
    cout << " --------------" << endl;
    cout << "| ";
    cout << "Iteration " << i << " |" << endl;
    cout << " --------------";
}

void print_design_timer(int i)
{
    cout << endl
         << " ---- " << endl;
    cout << "| ";
    cout << "t" << i << " |" << endl;
    cout << " ---- " << endl;
    cout << "     ";
}

void test_Time_methods()
{
    Time t1(8000);
    cout << "t1= " << t1 << endl;
    time_reset(t1);
    cout << "t1= " << t1 << endl;
}
void test_Time_operators()
{
    try
    {

        Time t1(50), t2(60);
        cout << "Operator Printer(cout)" << endl;
        cout << endl;

        cout << "t1 : " << t1 << endl;
        cout << "t2 : " << t2 << endl;

        cout << endl;

        cout << "operator += btween time objects" << endl;
        cout << "t1 += t2 : ";
        cout << (t1 += t2)<<endl;

        cout << endl;

        cout << "operator += btween time object and constant" << endl;
        cout << "t1 += 70 : ";
        cout << (t1 += 70)<<endl;

        cout << endl;

        cout << "operator + btween 2 time objects" << endl;
        cout << "t1 + t2 : ";
        cout << (t1 + t2)<<endl;

        cout << endl;

        cout << "operator + object time and constant" << endl;
        cout << "I) t1 + 70 : ";
        cout << (t1 + 70)<<endl;

        cout << endl;

        cout << "II) 70 + t1 : ";
        cout << (70 + t1) << endl;

        cout << endl;

        cout << "operators == , != , < , > , <= , >= btween 2 time objects" << endl;
        cout << endl;
        cout << "t1 : " << t1 << endl;
        cout << "t2 : " << t2 << endl;
        cout << endl;
        cout << "t1 == t2 : ";
        t1 == t2 ? cout << "Ture" << endl : cout << "False" << endl;

        cout << "t1 != t2 : ";
        t1 != t2 ? cout << "Ture" << endl : cout << "False" << endl;

        cout << "t1 > t2  : ";
        t1 > t2 ? cout << "True" << endl : cout << "False" << endl;

        cout << "t1 < t2  : ";
        t1 < t2 ? cout << "True" << endl : cout << "False" << endl;

        cout << "t1 >= t2 : ";
        t1 >= t2 ? cout << "True" << endl : cout << "False" << endl;

        cout << "t1 <= t2 : ";
        t1 <= t2 ? cout << "True" << endl : cout << "False" << endl;
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}


void run_timer_1()
{
    try
    {
        Time target(1.5 * ONE_HOUR);
        MsgPrinter msg("Hello World!");

        Timer timer(target, &msg);

        for (int i = 0; i < 50; i++)
        {
            cout << "iteration number: " << i << ": " << timer.get_clock() << endl;

            timer.tick("Min", 2);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void run_timer_2()
{
    try
    {
        Time target(7);

        MsgPrinter msg("Seven Seconds");

        Timer timer(target, &msg);

        for (int i = 0; i < 10; i++)
        {
            cout << "iteration number: " << i << ": " << timer.get_clock() << endl;

            timer.tick();
            sleep(1);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void run_timer_3()
{

    string first = string("msg_printer_class");
    string second = string("msg_printer_surr.._class");
    string third = string("msg_printer_surr.._class");

    MsgPrinter *printer[3] = {
        new MsgPrinter(first),
        new MsgPrinterSurrounding(second, "--start--", "--end--"),
        new MsgPrinterMultipleSurrounding(third, ">>>>>", "<<<<<")};

    Time times[5] = {Time(10), Time(15), Time(20), Time(25), Time(30)};

    Timer t1(times[0], printer[0]);
    Timer t2(times[1], printer[1]);
    Timer t3(times[2], printer[1]);
    Timer t4(times[3], printer[2]);
    Timer t5(times[4], printer[2]);

    for (int i = 0; i < 40; i++)
    {
        print_design_iterator(i);

        print_design_timer(1);
        t1.tick();

        print_design_timer(2);
        t2.tick();

        print_design_timer(3);
        t3.tick();

        print_design_timer(4);
        t4.tick();

        print_design_timer(5);
        t5.tick();

        sleep(1);
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
        delete printer[i];
}

void run_timer_4()
{
    string first = string("msg_printer_class");
    string second = string("msg_printer_surr.._class");
    string third = string("msg_printer_surr.._class");

    MsgPrinter *printer[3] = {
        new MsgPrinter(first),
        new MsgPrinterSurrounding(second, "--start--", "--end--"),
        new MsgPrinterMultipleSurrounding(third, ">>>>>", "<<<<<")};

    Time times[5] = {Time(10), Time(15), Time(20), Time(25), Time(30)};

    list<Timer> timers_list;

    timers_list.push_back(Timer(times[0], printer[0]));
    timers_list.push_back(Timer(times[1], printer[1]));
    timers_list.push_back(Timer(times[2], printer[1]));
    timers_list.push_back(Timer(times[3], printer[2]));
    timers_list.push_back(Timer(times[4], printer[2]));
    list<Timer>::iterator it;

    for (int i = 0; i < 80; i++)
    {

        print_design_iterator(i);
        cout << endl;
        for (it = timers_list.begin(); it != timers_list.end(); it++)
        {
            (*it).tick();
            cout << endl;
        }
    }

    for (int i = 0; i < 3; i++)
        delete printer[i];
}
