#include "linked-list.hpp"
#include <tracked.hpp>

#pragma once

namespace datastructures
{
    template <typename T>
    LinkedList<T>::LinkedList() noexcept
        : mSize{0}, mHead{nullptr}, mTail{nullptr}
    {
    }

    template <typename T>
    const size_t LinkedList<T>::Size() const
    {
        return mSize;
    }

    template <typename T>
    void LinkedList<T>::Add(T value)
    {
        auto newNode = std::make_unique<Node>(std::move(value));

        if (!mHead)
        {
            mHead = std::move(newNode);
            mTail = mHead.get();
        }
        else
        {
            mTail->next = std::move(newNode);
            mTail = mTail->next.get();
        }

        ++mSize;
    }

    template class LinkedList<int>;
    template class LinkedList<Tracked>;
}
