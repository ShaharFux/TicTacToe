#ifndef TICTACTOE_BLOCKOPPONENT_H
#define TICTACTOE_BLOCKOPPONENT_H

#include "Strategy.h"

class BlockOpponent : public Strategy {
public:
    Position execute(const Board& board, char player) const override;
};

#endif //TICTACTOE_BLOCKOPPONENT_H
