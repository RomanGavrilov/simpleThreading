#pragma once

#include <memory>

namespace datastructures
{
    template <typename T>
    class LinkedList
    {
    public:
        explicit LinkedList() noexcept;
        const size_t Size() const;
        void Add(T value);

    private:
        struct Node
        {
            T value;
            std::unique_ptr<Node> next;
        };

    private:
        std::unique_ptr<Node> mHead;
        Node *mTail;
        size_t mSize;
    };
}
