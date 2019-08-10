
void run_timer_2()
{
    try
    {
        Time target(7);
        MsgPrinter msg("Seven Seconds");

        Timer timer(target, &msg);

        for (int i = 0; i < 10; i++)
        {
            timer.tick();
            sleep(1);

            cout << "iteration number: " << i + 1 << ": " << timer.get_clock() << endl;
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
            timer.tick("Min", 2);

            cout << "iteration number: " << i + 1 << ": " << timer.get_clock() << endl;

        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
