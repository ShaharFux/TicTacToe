#include "Board/Board.h"
#include "Player/Player.h"
#include "Strategies/AnyOpenCorner.h"
#include "Strategies/AnyOpenSquare.h"
#include "Strategies/BlockOpponent.h"
#include "Strategies/PlayToWin.h"
#include <iostream>
#include <memory>

int main() {
    Board board;
    Player player1('X');
    Player player2('O');

    Player* current_player = &player1;

    while (true) {
        board.print_board();

        // Choose strategy for current player
        int strategy_choice;
        std::cout << "Choose strategy for player " << current_player->get_piece() << " (1: AnyOpenSquare, 2: AnyOpenCorner, 3: BlockOpponent, 4: PlayToWin, 5: Manual Move): ";
        std::cin >> strategy_choice;

        std::shared_ptr<Strategy> strategy;
        if (strategy_choice == 5) {
            Position move = current_player->get_move(board);
            board.set_piece_at(move.x, move.y, current_player->get_piece());
        } else {
            switch (strategy_choice) {
                case 1:
                    strategy = std::make_shared<AnyOpenSquare>();
                    break;
                case 2:
                    strategy = std::make_shared<AnyOpenCorner>();
                    break;
                case 3:
                    strategy = std::make_shared<BlockOpponent>();
                    break;
                case 4:
                    strategy = std::make_shared<PlayToWin>();
                    break;
                default:
                    std::cerr << "Invalid strategy choice. Try again.\n";
                    continue;
            }

            try {
                current_player->make_move(board, *strategy);
            } catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
                continue;
            }
        }

        if (board.has_winner()) {
            board.print_board();
            std::cout << "Player " << current_player->get_piece() << " Wins!\n";
            break;
        }

        if (board.is_full()) {
            board.print_board();
            std::cout << "It's a tie!\n";
            break;
        }

        current_player = (current_player == &player1) ? &player2 : &player1;

    }

    return 0;
}
