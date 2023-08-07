#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class OthelloGame {
private:
    char board[8][8];
    char currentPlayer;

public:
    OthelloGame() {
        currentPlayer = 'b';
        initializeBoard();
    }

    void initializeBoard() {
        for (auto& row : board) {
            for (char& cell : row) {
                cell = '-';
            }
        }

        board[3][3] = 'w';
        board[3][4] = 'b';
        board[4][3] = 'b';
        board[4][4] = 'w';
    }

    void printBoard() {
        std::cout << "   0  1  2  3  4  5  6  7\n";
        for (int i = 0; i < 8; ++i) {
            std::cout << (i) << "  ";
            for (int j = 0; j < 8; ++j) {
                std::cout << board[i][j] << "  ";
            }
            std::cout << '\n';
        }
    }

    bool isGameOver() {
        return getLegalMoves().empty();
    }

    std::vector<std::vector<int>> getLegalMoves() {
        std::vector<std::vector<int>> moveList;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == '-' && isFlippable(i, j)) {
                    moveList.push_back({i, j});
                }
            }
        }

        return moveList;
    }

    bool isFlippable(int row, int col) {
        char otherPlayer = (currentPlayer == 'b') ? 'w' : 'b';

        int surroundingPosDeltas[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                          {0, -1}, {0, 1},
                                          {1, -1}, {1, 0}, {1, 1}};

        for (auto deltas : surroundingPosDeltas) {
            if (row + deltas[0] > 7 || row + deltas[0] < 0 || col + deltas[1] > 7 || col + deltas[1] < 0) {
                continue;
            }

            char char_in_pos = board[row + deltas[0]][col + deltas[1]];

            if (char_in_pos == otherPlayer) {
                int curr_row = row + deltas[0];
                int curr_col = col + deltas[1];

                while (char_in_pos == otherPlayer) {
                    curr_row += deltas[0];
                    curr_col += deltas[1];

                    if (curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_row < 0)
                        break;

                    char_in_pos = board[curr_row][curr_col];
                }

                if (char_in_pos == currentPlayer)
                    return true;
            }
        }

        return false;
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
        flip(row, col);
        currentPlayer = (currentPlayer == 'b') ? 'w' : 'b';
    }

    void flip(int row, int col) {
        std::vector<std::vector<int>> discs_to_flip;

        char otherPlayer = (currentPlayer == 'b') ? 'w' : 'b';

        int surroundingPosDeltas[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                          {0, -1}, {0, 1},
                                          {1, -1}, {1, 0}, {1, 1}};

        for (auto deltas : surroundingPosDeltas) {
            int curr_row = row + deltas[0];
            int curr_col = col + deltas[1];

            if (curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_col < 0)
                continue;

            char char_in_pos = board[curr_row][curr_col];

            bool flip_this_direction = false;

            if (char_in_pos == otherPlayer) {
                while (char_in_pos == otherPlayer) {
                    curr_row += deltas[0];
                    curr_col += deltas[1];

                    if (curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_col < 0)
                        break;

                    char_in_pos = board[curr_row][curr_col];
                }

                if (char_in_pos == currentPlayer)
                    flip_this_direction = true;

                if (flip_this_direction) {
                    curr_row = row + deltas[0];
                    curr_col = col + deltas[1];
                    char_in_pos = board[curr_row][curr_col];

                    while (char_in_pos == otherPlayer) {
                        std::vector<int> disc = {curr_row, curr_col};
                        discs_to_flip.push_back(disc);
                        curr_row += deltas[0];
                        curr_col += deltas[1];

                        char_in_pos = board[curr_row][curr_col];
                    }
                }
            }
        }

        for (auto pos : discs_to_flip)
            board[pos[0]][pos[1]] = currentPlayer;
    }
};

int main() {
    OthelloGame game;

    while (!game.isGameOver()) {
        game.printBoard();

        std::vector<std::vector<int>> moveList = game.getLegalMoves();
        if (moveList.empty()) {
            std::cout << "No legal moves for the current player. Skipping turn.\n";
            game.makeMove(-1, -1);  // Pass turn
            continue;
        }

        std::cout << "Legal moves: ";
        for (const auto& move : moveList) {
            std::cout << "(" << move[0] << "," << move[1] << ") ";
        }
        std::cout << std::endl;

        int row, col;
        std::cout << "Enter your move (row column): ";
        std::cin >> row >> col;

        if (std::find(moveList.begin(), moveList.end(), std::vector<int>{row, col}) != moveList.end()) {
            game.makeMove(row, col);
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    game.printBoard();
    std::cout << "Game over!\n";

    return 0;
}