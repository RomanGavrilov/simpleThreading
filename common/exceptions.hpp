#pragma once

#include <iostream>
#include <exception>

struct RuntimeException : std::runtime_error
{
    explicit RuntimeException(std::string what);

    [[noreturn]] static void RethrowNested(const std::string &what);
};

void RuntimeException::RethrowNested(const std::string &what)
{
    std::throw_with_nested(RuntimeException(what));
}

RuntimeException::RuntimeException(std::string what)
    : std::runtime_error{std::move(what)}
{
}

#define RETHROW_NESTED(message) RuntimeException::RethrowNested(message)

void log_nested_exception(const std::exception &e)
{
    std::cerr << e.what() << std::endl;
    try
    {
        std::rethrow_if_nested(e);
    }
    catch (const std::exception &nested)
    {
        log_nested_exception(nested);
    }

    catch (...)
    {
        std::cerr << "Unknown exception\n";
    }
}

void log_nested_exception_ptr(const std::exception_ptr &eptr)
{
    try
    {
        if (eptr) 
        {
            std::rethrow_exception(eptr);
        }   
    }
    catch (const std::exception &e)
    {
        log_nested_exception(e);
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
    }
}

#define LOG_EXCEPTION(e)         \
    do                           \
    {                            \
        log_nested_exception(e); \
    } while (0)

#define LOG_EXCEPTION_PTR(e)         \
    do                           \
    {                            \
        log_nested_exception_ptr(e); \
    } while (0)
