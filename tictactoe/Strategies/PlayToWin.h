#ifndef TICTACTOE_PLAYTOWIN_H
#define TICTACTOE_PLAYTOWIN_H

#include "Strategy.h"

class PlayToWin : public Strategy {
public:
    Position execute(const Board& board, char player) const override;
};

#endif //TICTACTOE_PLAYTOWIN_H
