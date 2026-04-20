#include <gtest/gtest.h>
#include <trie/trie.hpp>
#include <console-logger.hpp>

using namespace std;
using namespace datastructures;

TEST(TrieTests, testinit)
{
    vector<Trie::Vertex> trie(1);

    EXPECT_EQ(trie.size(), 1);
}
