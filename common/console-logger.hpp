#pragma once
#include <iostream>
#include <mutex>
#include <string_view>

namespace common
{

    class ConsoleLogger
    {
    public:
        ConsoleLogger() noexcept : mStream(std::cout) {}

        ConsoleLogger(const ConsoleLogger &) = delete;
        ConsoleLogger &operator=(const ConsoleLogger &) = delete;
        ConsoleLogger(ConsoleLogger &&) = delete;
        ConsoleLogger &operator=(ConsoleLogger &&) = delete;

        ~ConsoleLogger() noexcept = default;

        void Log(std::string_view message)
        {
            std::scoped_lock lock{mMutex};
            mStream << message << '\n';
        }

    private:
        std::mutex mMutex;
        std::ostream &mStream;
    };

} // namespace common
