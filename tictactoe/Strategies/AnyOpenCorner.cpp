#include "AnyOpenCorner.h"

Position AnyOpenCorner::execute(const Board &board, char player) const {
    if (board.get_piece_at(0, 0) == ' ') return Position(0, 0);
    else if (board.get_piece_at(0, 2) == ' ') return Position(0, 2);
    else if (board.get_piece_at(2, 0) == ' ') return Position(2, 0);
    else if (board.get_piece_at(2, 2) == ' ') return Position(2, 2);

    throw std::runtime_error("No open corners available");
}