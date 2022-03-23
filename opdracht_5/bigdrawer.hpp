#ifndef BIGDRAWER_HPP
#define BIGDRAWER_HPP
#include "circle.hpp"
#include "cross.hpp"
#include "game.hpp"
#include "tictactoedrawable.hpp"
#include "tictactoegrid.hpp"
class BigDrawer : public Tictactoedrawable
{
public:
    BigDrawer(sf::RenderWindow &window, Game &game, TicTacToeGrid &grid)
        : Tictactoedrawable(window), game(game), grid(grid){};

    void draw()
    {
        items itemToDraw = items::EMPTY;
        auto moves = game.getMoves();
        if (moves.size() > 0)
        {
            for (auto &move : moves)
            {
                if (move.what == 'x')
                {
                    itemToDraw = items::CROSS;
                }
                else if (move.what == 'o')
                {
                    itemToDraw = items::CIRCLE;
                }
                else
                {
                    itemToDraw = items::EMPTY;
                }
                for (auto &spot : grid.gridSpotArray)
                {
                    if (spot->getGridPosition()[0] == move.where[0] && spot->getGridPosition()[1] == move.where[1])
                    {
                        switch (itemToDraw)
                        {
                        case (items::CROSS):
                        {
                            auto cross = Cross(window, spot->getCenterPosition());
                            cross.draw();
                            break;
                        }
                        case (items::CIRCLE):
                        {
                            auto circle = Circle(window, spot->getCenterPosition());
                            circle.draw();
                            break;
                        }
                        case (items::EMPTY):
                        {
                            break;
                        }
                        }
                    }
                }
            }
        }
    }

private:
    Game &game;
    TicTacToeGrid &grid;
    enum class items
    {
        CROSS,
        CIRCLE,
        EMPTY
    };
};
#endif // BIGDRAWER_HPP
