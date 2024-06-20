
#ifndef TICTACTOE_ANYOPENCORNER_H
#define TICTACTOE_ANYOPENCORNER_H

#include "Strategy.h"

class AnyOpenCorner : public Strategy {
public:
    Position execute(const Board& board, char player) const override;
};

#endif //TICTACTOE_ANYOPENCORNER_H
