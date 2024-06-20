#include "BlockOpponent.h"

Position BlockOpponent::execute(const Board &board, char player) const {
    char opponent = (player == 'X') ? 'O' : 'X';
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (board.get_piece_at(x, y) == ' ' && board.can_win(x, y, opponent)) {
                return Position(x, y);
            }
        }
    }
    throw std::runtime_error("No blocking move available");
}