#include <gtest/gtest.h>
#include <linked-list.hpp>
#include <tracked.hpp>
#include <console-logger.hpp>

using datastructures::LinkedList;

TEST(LinkedListTest, InitiallyEmpty)
{
    LinkedList<int> a;
    EXPECT_EQ(a.Size(), 0u);

    LinkedList<int> b{};
    EXPECT_EQ(b.Size(), 0u);

    const auto c = new LinkedList<int>();
    EXPECT_EQ(c->Size(), 0u);
}

TEST(LinkedListTest, AddIncreasesSize)
{
    LinkedList<int> list;
    list.Add(10);
    EXPECT_EQ(list.Size(), 1u);

    list.Add(20);
    EXPECT_EQ(list.Size(), 2u);
}

TEST(LinkedListTest, DeallocatesOnDestruction)
{
    Tracked::live = 0;

    {
        LinkedList<Tracked> list;
        EXPECT_EQ(Tracked::live.load(), 0);

        list.Add(Tracked{1});
        list.Add(Tracked{2});
        list.Add(Tracked{3});

        EXPECT_EQ(list.Size(), 3u);
        EXPECT_EQ(Tracked::live.load(), 3);
    }

    EXPECT_EQ(Tracked::live.load(), 0);
}

TEST(LinkedListTest, ThreadSafeAdd)
{
    constexpr int N {20};
    std::vector<std::thread> threads;
    threads.reserve(N);

    common::ConsoleLogger logger;

    const auto threadProc = [&logger](int id)
    {
        logger.Log(std::to_string(id));
    };

    for (int i = 0; i < N; ++i)
    {
        threads.emplace_back(threadProc, i);
    }

    for (auto &t : threads)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}