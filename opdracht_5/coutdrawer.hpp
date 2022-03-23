#ifndef COUTDRAWER_HPP
#define COUTDRAWER_HPP
#include "game.hpp"
class coutDrawer
{
public:
    coutDrawer(Game &game) : game(game){printBoard();};

    void coutGame()
    {
        char c;
        std::cin >> c;
        for (auto &command : commands)
        {
            if (command.key == c)
            {
                game.addMove(command.where[0], command.where[1]);
            }
        }
        if (c == '0')
        {
            game.popLastMove();
        }
        printf("\033[H\033[J");
        printBoard();
    }

private:
    typedef std::array<int, 2> coo;
    Game &game;
    struct Command
    {
        char key;
        coo where;
    };
    std::array<Command, 9> commands = {
        Command{'7', {0, 0}},
        Command{'8', {1, 0}},
        Command{'9', {2, 0}},
        Command{'4', {0, 1}},
        Command{'5', {1, 1}},
        Command{'6', {2, 1}},
        Command{'1', {0, 2}},
        Command{'2', {1, 2}},
        Command{'3', {2, 2}}};
    void printBoard()
    {
        std::cout << game.moves[0].what << " | " << game.moves[1].what << " | " << game.moves[2].what << "\n";
        std::cout << "---------\n";
        std::cout << game.moves[3].what << " | " << game.moves[4].what << " | " << game.moves[5].what << "\n";
        std::cout << "---------\n";
        std::cout << game.moves[6].what << " | " << game.moves[7].what << " | " << game.moves[8].what << "\n";
    }
};

#endif //COUTDRAWER_HPP