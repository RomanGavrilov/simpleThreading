#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

class Counter
{
public:
    Counter()
        : mCount{0}, mStopRequested{false}
    {
    }

    ~Counter()
    {
        mStopRequested = true;
        if (mExecutor.joinable())
        {
            try
            {
                mExecutor.join();
            }
            catch (...)
            {
                auto eptr = std::current_exception();

                try
                {
                    if (eptr)
                    {
                        std::rethrow_exception(eptr);
                    }
                }
                catch (const std::exception &e)
                {
                    std::cout << "Something went wrong: " << e.what() << '\n';
                }
                catch (...)
                {
                    std::cout << "Something went wrong: unknown exception\n";
                }
            }
        }
    }

    void Start(uint64_t startAt)
    {
        mStopRequested = false;
        mCount = startAt;
        cout << "Started at: " << mCount << '\n';

        mExecutor = thread(
            [this]()
            { InternalStart(); });
    }

    uint64_t Stop()
    {
        mStopRequested = true;
        if (!mExecutor.joinable())
        {
            return mCount;
        }

        mExecutor.join();
        return mCount;
    }

private:
    void InternalStart()
    {
        while (!mStopRequested)
        {
            ++mCount;
            this_thread::sleep_for(2ms);
        }
    }

    uint64_t mCount;
    atomic<bool> mStopRequested;
    thread mExecutor;
};

int main()
{
    Counter counter;

    counter.Start(0);
    this_thread::sleep_for(500ms);
    auto res{counter.Stop()};

    counter.Start(res);
    this_thread::sleep_for(500ms);
    res = counter.Stop();

    counter.Start(res);
    this_thread::sleep_for(500ms);
    res = counter.Stop();

    counter.Start(res);
    this_thread::sleep_for(500ms);
    res = counter.Stop();

    counter.Start(res);
    this_thread::sleep_for(500ms);
    res = counter.Stop();

    counter.Start(res);
    this_thread::sleep_for(500ms);
    res = counter.Stop();

    counter.Start(res);
    this_thread::sleep_for(500ms);
    res = counter.Stop();


    cout << "Result: " << res << '\n';

    return 0;
}
