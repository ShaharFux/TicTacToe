#include "PlayToWin.h"

Position PlayToWin::execute(const Board &board, char player) const {
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (board.get_piece_at(x, y) == ' ' && board.can_win(x, y, player)) {
                return Position(x, y);
            }
        }
    }
    throw std::runtime_error("No winning move available");
}