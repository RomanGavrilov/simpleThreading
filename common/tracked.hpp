#pragma once

#include <atomic>

struct Tracked
{
    static inline std::atomic<int> live{0};

    int v{};
    Tracked(int x) : v(x) { ++live; }
    Tracked(const Tracked &other) : v(other.v) { ++live; }
    Tracked(Tracked &&other) noexcept : v(other.v) { ++live; }
    ~Tracked() { --live; }
};