#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace datastructures
{
    class Trie
    {
    public:
        struct Vertex
        {
            int next[26];
            bool output = false;

            Vertex()
            {
                std::fill(std::begin(next), std::end(next), -1);
            }
        };

        Trie() noexcept;
        inline size_t Size() const noexcept;
        void Add(const std::string &s) noexcept;
        inline int Link(int vertex, const char c) const noexcept;
        inline bool Contains(const std::string &s) const noexcept;

    private:
        std::vector<Vertex> mVertices;
    };
}
