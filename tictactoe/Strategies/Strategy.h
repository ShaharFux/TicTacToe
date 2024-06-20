#ifndef TICTACTOE_STRATEGY_H
#define TICTACTOE_STRATEGY_H

#include "../Board/Board.h"
#include "../Position.h"
#include <stdexcept>

class Strategy {
public:
    virtual Position execute(const Board& board, char player) const = 0;
};


#endif //TICTACTOE_STRATEGY_H
