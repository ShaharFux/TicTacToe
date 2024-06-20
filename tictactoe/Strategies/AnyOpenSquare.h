#ifndef TICTACTOE_ANYOPENSQUARE_H
#define TICTACTOE_ANYOPENSQUARE_H

#include "Strategy.h"

class AnyOpenSquare : public Strategy {
public:
    Position execute(const Board& board, char player) const override;
};

#endif //TICTACTOE_ANYOPENSQUARE_H
