
#include "trie.hpp"
namespace datastructures
{
    Trie::Trie() noexcept
        : mVertices(1)
    {
    }

    inline size_t Trie::Size() const noexcept
    {
        return mVertices.size();
    }

    inline int Trie::Link(int vertex, const char c) const noexcept
    {
        return mVertices[vertex].next[c - 'a'];
    }

    void Trie::Add(const std::string &s) noexcept
    {
        int v = 0;
        for (char c : s)
        {
            const int ch{c - 'a'};
            if (-1 == mVertices[v].next[ch])
            {
                mVertices[v].next[ch] = Size();
                mVertices.emplace_back();
            }

            v = mVertices[v].next[ch];
        }

        mVertices[v].output = true;
    }

    inline bool Trie::Contains(const std::string &s) const noexcept
    {
        int v = 0;
        for (char c : s)
        {
            const int link{Link(v, c)};
            if (-1 == link)
            {
                return false;
            }

            v = link;
        }

        return mVertices[v].output;
    }
}