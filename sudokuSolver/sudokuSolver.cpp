
#include <iostream>
#include <bitset>
#include <functional>
#include <array>
#include <vector>


constexpr std::size_t get_pos(std::size_t row, std::size_t col) noexcept
{
    return row / 3 * 3 + col / 3;
}

constexpr std::size_t get_next_row(int row, int col) noexcept
{
    if (col == 8)
        return row + 1;
    else
        return row;
}

constexpr std::size_t get_next_col(int col) noexcept
{
    return (col + 1) % 9;
}


class Solution
{
private:
    static constexpr std::pair<std::size_t, std::size_t> next_empty_cell(std::vector<std::vector<char>>& board, int _row, int _col)noexcept
    {
        while (_row != 9)
        {
            if (board[_row][_col] == '.')
                return { _row, _col };
            _row = get_next_row(_row, _col);
            _col = get_next_col(_col);            
        }

        return { 9, 0 };
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) const noexcept
    {
        std::array<std::bitset<9>, 9> in_row = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        std::array<std::bitset<9>, 9> in_col = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        std::array<std::bitset<9>, 9> in_cell = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        for (std::size_t r = 0; r < board.size(); r++)
        {
            for (std::size_t c = 0; c < board[0].size(); c++)
            {
                std::size_t val = board[r][c];
                if (val != '.')
                {
                    std::size_t val_index = val - '1';
                    in_row[r].set(val_index);
                    in_col[c].set(val_index);
                    std::size_t pos_in3by3 = get_pos(r, c);
                    in_cell[pos_in3by3].set(val_index);
                }
            }
        }

        std::function<bool(int, int)>  backtrack = [&](int start_row, int start_col) noexcept
        {
            auto id = next_empty_cell(board, start_row, start_col);

            if (id.first == 9)
                return true;

            const std::size_t pos = get_pos(id.first, id.second);
            std::bitset<9> const contains = in_row[id.first] | in_col[id.second] | in_cell[pos];

            if (contains.all())
                return false;

            for (std::size_t valIdx = 0; valIdx < 9; ++valIdx)
            {
                if (!contains[valIdx])
                {
                    board[id.first][id.second] = static_cast<char>(valIdx + '1');
                    in_row[id.first].set(valIdx);
                    in_col[id.second].set(valIdx);
                    in_cell[pos].set(valIdx);

                    bool solved = backtrack(id.first, id.second);

                    if (solved)
                        return true;

                    in_row[id.first].reset(valIdx);
                    in_col[id.second].reset(valIdx);
                    in_cell[pos].reset(valIdx);
                }
            }
            board[id.first][id.second] = '.';
            return false;
        };

        backtrack(0, 0);
    }


    void print_board(std::vector<std::vector<char>>& board) noexcept
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                std::cout << board[i][j] << ',';
            }
            std::cout << "\n";
        }
    }
};




int main()
{
    std::vector<std::vector<char>> vec = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
                                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
                                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
                                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
                                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
                                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
                                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
                                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

    Solution soln;
    soln.solveSudoku(vec);

    soln.print_board(vec);

    return 0;
}
