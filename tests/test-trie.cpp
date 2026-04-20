#include <gtest/gtest.h>
#include <trie/trie.hpp>
#include <console-logger.hpp>

using namespace std;
using namespace datastructures;

TEST(TrieTests, InitRoot)
{
    Trie trie;

    EXPECT_EQ(trie.Size(), 1);
}

TEST(TrieTests, AddOneString)
{
    Trie trie;
    trie.Add("abc");
    EXPECT_TRUE(trie.Contains("abc"));
    EXPECT_FALSE(trie.Contains("ab"));
}

TEST(TrieTests, AddMultipleStrings)
{
    Trie trie;
    trie.Add("a");
    trie.Add("abc");
    trie.Add("fgeahskdh");

    EXPECT_TRUE(trie.Contains("a"));
    EXPECT_FALSE(trie.Contains("ab"));
    EXPECT_TRUE(trie.Contains("abc"));
    EXPECT_TRUE(trie.Contains("fgeahskdh"));
}