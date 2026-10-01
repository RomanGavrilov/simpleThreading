

#include <iostream>
#include "n-queens.hpp"

#define E '-'
#define Q 'Q'

namespace alg
{

    using namespace std;

    Board::Board(int size) noexcept
        : N{size}, data(N, vector<char>(N, E))
    {
    }

    bool Board::Place(int row, int col) noexcept
    {
        // check col
        for (int i = row; i >= 0; --i)
        {
            if (Q == data[i][col])
            {
                return false;
            }
        }

        // check row
        for (int j = col; j >= 0; --j)
        {
            if (Q == data[row][j])
            {
                return false;
            }
        }

        // check lr diag
        for (int i = row, j = col; i >= 0, j >= 0; --i, --j)
        {
            if (Q == data[i][j])
            {
                return false;
            }
        }

        // check rl diag
        for (int i = row, j = col; i >= 0, j < N; --i, ++j)
        {
            if (Q == data[i][j])
            {
                return false;
            }
        }

        return true;
    }

    void Board::Print() noexcept
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {

                cout << data[i][j] << " ";
            }
            cout << '\n';
        }

        cout << '\n';
    }
}