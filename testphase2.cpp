
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

void run_timer_3()
{
    string s = string("Hi");
    MsgPrinter *printer[1];

    printer[0] = new MsgPrinter(s);
    printer[1]=new MsgPrinterSurrounding(s,"--start--","--end--");
    printer[2]=new MsgPrinterMultipleSurrounding(s,">>>>>","<<<<<");
    printer[0][0].print();
    cout<<"*****************************"<<endl;
    cout<<"*****************************"<<endl;

    printer[1][0].print();
    cout<<"*****************************"<<endl;
    cout<<"*****************************"<<endl;
    
    delete printer[0];
    delete printer[1];
    //delete printer[2];


}