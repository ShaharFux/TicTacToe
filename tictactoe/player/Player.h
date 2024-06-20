#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "../Board/Board.h"
#include "../Strategies/Strategy.h"

class Player {
public:
    Player(char piece);
    Position get_move(const Board& board) const;
    char get_piece() const;
    void make_move(Board& board, const Strategy& strategy);

private:
    char piece;
};



#endif //TICTACTOE_PLAYER_H
