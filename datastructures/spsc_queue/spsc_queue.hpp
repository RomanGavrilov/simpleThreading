#pragma once

#include <array>
#include <emmintrin.h>
#include <algorithm>
#include <utility>

#define FORCE_INLINE inline __attribute__((always_inline))
#define UNLIKELY(condition) \
    __builtin_expect(static_cast<bool>(condition), 0)

template <class T, size_t size>
class spsc_queue
{
private:
    volatile __attribute__((aligned(64))) uint64_t stopFlag = 0;
    volatile __attribute__((aligned(64))) uint64_t pread    = 0;
    volatile __attribute__((aligned(64))) uint64_t pwrite   = 0;

    __attribute__((aligned(64))) std::array<const T*, size> buffer;

public:
    spsc_queue()
    {
        std::fill(buffer.begin(), buffer.end(), nullptr);
    }

    FORCE_INLINE bool empty() const
    {
        return buffer[pread] == nullptr;
    }

    FORCE_INLINE bool available() const
    {
        return buffer[pwrite] == nullptr;
    }

    FORCE_INLINE void push(const T* data)
    {
        while (!stopFlag && !available())
        {
            _mm_pause();
        }

        if (UNLIKELY(stopFlag))
        {
            return;
        }

        buffer[pwrite] = data;
        pwrite = (pwrite + 1) % size;
    }

    FORCE_INLINE const T* pop()
    {
        while (!stopFlag && empty())
        {
            _mm_pause();
        }

        const T* result = nullptr;

        if (UNLIKELY(stopFlag))
        {
            return result;
        }

        result = buffer[pread];
        buffer[pread] = nullptr;
        pread = (pread + 1) % size;

        return result;
    }

    FORCE_INLINE void stop()
    {
        stopFlag = 1;
    }
};