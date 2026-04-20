#pragma once

#include <algorithm>
#include <string>

namespace datastructures
{
    namespace Trie
    {
        struct Vertex
        {
            int next[26];
            bool output = false;

            Vertex()
            {
                std::fill(std::begin(next), std::end(next), -1);
            }
        };

        inline void Add(const std::string &s) noexcept
        {
            if (0 == s.size())
            {
                return;
            }

            // Trie storage and insertion logic will live here once the
            // container interface is fleshed out.
        }
    }
}
