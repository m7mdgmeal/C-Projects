#include "my_timer.h"
#include <unistd.h>
#include <list>

#include <iterator>

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
void test()
{
    string base = "TTTTTTTTTTTTTTTTT";
    MsgPrinter m(base);

    Time t(10);
    Timer t1(t, &m);

    for (int i = 0; i < 40; i++)
    {
        cout << "Iteration " << i << ":";
        t1.tick();
        cout << endl;
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
        cout << "Iteration " << i << ":" << endl;
        cout << "t1: ";
        t1.tick();
        cout << endl;
        cout << "t2: ";
        cout << endl;

        t2.tick();
        cout << "t3: ";
        cout << endl;

        t3.tick();
        cout << "t4: ";
        cout << endl;

        t4.tick();
        cout << "t5: ";
        cout << endl;

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

    for (int i = 0; i < 80; i++)
    {
        cout << "Iteration " << i << ": " << endl;
        list<Timer>::iterator it;
        for (it = timers_list.begin(); it != timers_list.end(); it++)
        {
            (*it).tick();
            cout << endl;
        }
            sleep(1);

    }

    for (int i = 0; i < 3; i++)
        delete printer[i];
}