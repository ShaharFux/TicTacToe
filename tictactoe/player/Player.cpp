#include "Player.h"
#include <iostream>
#include <limits>

Player::Player(char piece) :
    piece(piece)
{}

Position Player::get_move(const Board &board) const {
    int x, y;
    while (true) {
        std::cout << "Enter your move (row and column): ";
        std::cin >> x >> y;
        if (std::cin.fail() || x < 0 || x > 2 || y < 0 || y > 2) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
            std::cout << "Invalid input. Please enter numbers between 0 and 2.\n";
        } else if (board.get_piece_at(x, y) != ' ') {
            std::cout << "The position is already occupied. Please choose another one.\n";
        } else break;
    }

    return Position(x, y);
}

char Player::get_piece() const {
    return piece;
}

void Player::make_move(Board& board, const Strategy& strategy) {
    Position move = strategy.execute(board, piece);
    board.set_piece_at(move.x, move.y, piece);
}
