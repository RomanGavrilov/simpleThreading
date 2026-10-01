#pragma once
#include <vector>

using namespace std;

namespace alg
{
    class Board
    {
    public:
        Board(int size) noexcept;

        bool Place(int row, int col) noexcept;

        void Print() noexcept;

    private:
        int N;
        vector<vector<char>> data;
    };
}
