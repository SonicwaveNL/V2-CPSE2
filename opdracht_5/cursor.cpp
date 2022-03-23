#include "cursor.hpp"

void Cursor::command(Game &game, TicTacToeGrid &grid)
{
    if (cursor.isButtonPressed(sf::Mouse::Left))
    {
        for (auto &spot : grid.gridSpotArray)
        {
            if (spot->contains(from_vectorI_to_vectorf(cursor.getPosition(window))))
            {
                game.addMove(spot->getGridPosition()[0],spot->getGridPosition()[1]);
                sf::sleep(sf::milliseconds(100));
                break;
            }
        }
    }
}
sf::Vector2f Cursor::from_vectorI_to_vectorf(const sf::Vector2i &rhs)
{
    return sf::Vector2f(static_cast<float>(rhs.x), static_cast<float>(rhs.y));
}