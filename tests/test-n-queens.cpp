#include <gtest/gtest.h>
#include <trie/trie.hpp>
#include <n-queens.hpp>



TEST(NQueens, Place)
{
    alg::Board board(8);

    board.Place(0, 0);

    EXPECT_TRUE(1 < 0);
}
