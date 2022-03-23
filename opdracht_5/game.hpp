#ifndef GAME_HPP
#define GAME_HPP
#include "tictactoedrawable.hpp"
#include <stdio.h>
class Game
{
private:
    typedef std::array<int, 2> coo;
    struct Move
    {
        coo where;
        char what;
    };
    
    bool crossTurn = true;
    bool circleTurn = false;
    std::vector<Move> lastMoves;

public:
    std::vector<Move> moves;
    bool gameWon = false;
    Game()
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                Move move = {{x, y}, ' '};
                moves.push_back(move);
            }
        }
    }
    void addMove(const int x, const int y)
    {
        if (!gameWon)
        {
            char c;
            coo a = {x, y};
            if (crossTurn)
            {
                c = 'x';
                crossTurn = false;
                circleTurn = true;
            }
            else
            {
                c = 'o';
                crossTurn = true;
                circleTurn = false;
            }
            Move move = {a, c};
            for (auto &item : moves)
            {
                if (move.where == item.where && item.what != ' ')
                {
                    std::cout << "place already filled\n";
                    return;
                }
            }
            pushBack(move);
            winningMove();
        }
    }

    void command()
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !gameWon)
        {

            popLastMove();
            sf::sleep(sf::milliseconds(100));
        }
    }

    void clearMoves()
    {
        if (moves.size() > 0)
        {
            moves.clear();
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    Move move = {{x, y}, ' '};
                    moves.push_back(move);
                }
            }
        }
    }
    void popLastMove()
    {
        if (lastMoves.size() > 0)
        {
            for (auto &move : moves)
            {
                if (move.where == lastMoves[lastMoves.size() - 1].where)
                {
                    move.what = ' ';
                }
            }
            lastMoves.pop_back();
        }
        if (crossTurn)
            {
                crossTurn = false;
                circleTurn = true;
            }
            else
            {
                crossTurn = true;
                circleTurn = false;
            }
    }
    void pushBack(Move &move)
    {
        for (auto &item : moves)
        {
            if (item.where == move.where)
            {
                item.what = move.what;
            }
        }
        lastMoves.push_back(move);
    }
    Move peekLastMove()
    {
        return lastMoves[lastMoves.size() - 1];
    }

    std::vector<Move> getMoves()
    {
        return moves;
    }

    bool checkForWinOnLine(const Move &move1, const Move &move2, const Move &move3)
    {
        if (move1.what == ' ' || move2.what == ' ' || move3.what == ' ')
        {
            return false;
        }
        char array[3] = {move1.what, move2.what, move3.what};
        return array[0] == array[1] && array[1] == array[2] && array[2] == array[0];
    }

    void winningMove()
    {
        if (!gameWon)
        {
            if (checkForWinOnLine(moves[0], moves[3], moves[6]))
            {
                std::cout << moves[0].what << " wins!\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[1], moves[4], moves[7]))
            {
                std::cout << moves[1].what << " wins!\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[2], moves[5], moves[8]))
            {
                std::cout << moves[2].what << " wins!\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[0], moves[1], moves[2]))
            {
                std::cout << moves[0].what << " wins!\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[3], moves[4], moves[5]))
            {
                std::cout << moves[3].what << " wins!\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[6], moves[7], moves[8]))
            {
                std::cout << moves[6].what << " wins!\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[0], moves[4], moves[8]))
            {
                std::cout << moves[0].what << " wins\n";
                gameWon = true;
            }
            else if (checkForWinOnLine(moves[2], moves[4], moves[6]))
            {
                std::cout << moves[2].what << " wins\n";
                gameWon = true;
            }
            else if (moves.size() == 9)
            {
                int counter = 0;
                for (auto &move : moves)
                {
                    if (move.what != ' ')
                    {
                        counter++;
                    }
                    if (counter == 9)
                    {
                        gameWon = true;
                        std::cout << "draw\n";
                    }
                }
            }
        }
    }
};
#endif //GAME_HPP