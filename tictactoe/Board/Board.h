#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <vector>
#include "../Position.h"

class Board {
public:
    Board();
    char get_piece_at(int x, int y) const;
    void set_piece_at(int x, int y, char piece);
    bool is_full() const;
    bool has_winner() const;
    void print_board() const;
    bool is_winning_move(int x, int y, char player) const;
    bool can_win(int x, int y, char player) const;

private:
    std::vector<std::vector<char>> board;
};

#endif //TICTACTOE_BOARD_H

