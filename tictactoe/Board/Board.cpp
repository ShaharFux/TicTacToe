#include "Board.h"
#include <iostream>

Board::Board() :
    board(3, std::vector<char>(3, ' '))
{}

char Board::get_piece_at(int x, int y) const {
    if (x < 0 || x > 2 || y < 0 || y > 2)
        throw std::out_of_range("Coordinates out of range");
    return board[x][y];
}

void Board::set_piece_at(int x, int y, char piece) {
    if (x < 0 || x > 2 || y < 0 || y > 2)
        throw std::out_of_range("Coordinates out of range");
    board[x][y] = piece;
}

bool Board::is_full() const {
    for (const auto & row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

bool  Board::has_winner() const {
    // Check rows
    for (int i = 0; i < 3; ++i)
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

    // Check columns
    for (int i = 0; i < 3; ++i)
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;


    return false;
}

void Board::print_board() const {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << (cell == ' ' ? '.' : cell) << ' ';
        }
        std::cout << '\n';
    }
}

bool Board::is_winning_move(int x, int y, char player) const {
    // Check row
    bool win = true;
    for (int i = 0; i < 3; ++i) {
        if (board[x][i] != player && (x != i) || board[x][i] != ' ') {
            win = false;
            break;
        }
    }
    if (win) return true;

    // Check column
    win = true;
    for (int i = 0; i < 3; ++i) {
        if (board[i][y] != player && (y != i) || board[i][y] != ' ') {
            win = false;
            break;
        }
    }
    if (win) return true;

    // Check first diagonal (top-left to bottom-right)
    if (x == y) {
        win = true;
        for (int i = 0; i < 3; ++i) {
            if (board[i][i] != player && (x != i || board[i][i] != ' ')) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    // Check second diagonal (top-right to bottom-left)
    if (x + y == 2) {
        win = true;
        for (int i = 0; i < 3; ++i) {
            if (board[i][2 - i] != player && (x != i || board[i][2 - i] != ' ')) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    return false;
}

bool Board::can_win(int x, int y, char player) const {
    // Check row
    bool win = true;
    for (int i = 0; i < 3; ++i) {
        if (board[x][i] != player && i != y) {
            win = false;
            break;
        }
    }
    if (win) return true;

    // Check column
    win = true;
    for (int i = 0; i < 3; ++i) {
        if (board[i][y] != player && i != x) {
            win = false;
            break;
        }
    }
    if (win) return true;

    // Check first diagonal (top-left to bottom-right)
    if (x == y) {
        win = true;
        for (int i = 0; i < 3; ++i) {
            if (board[i][i] != player && i != x) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    // Check second diagonal (top-right to bottom-left)
    if (x + y == 2) {
        win = true;
        for (int i = 0; i < 3; ++i) {
            if (board[i][2 - i] != player && i != x) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    return false;
}