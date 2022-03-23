#include "tictactoegridspot.hpp"
TicTacToeGridSpot::TicTacToeGridSpot(const sf::Vector2f &position) : spot(position, sf::Vector2f(180, 146))
{
    int x;
    int y;
    if (position.x < 200)
    {
        x = 0;
    }
    else if (position.x > 200 && position.x < 400)
    {
        x = 1;
    }
    else
    {
        x = 2;
    }
    if (position.y < 146)
    {
        y = 0;
    }
    else if (position.y > 146 && position.y < 312)
    {
        y = 1;
    }
    else
    {
        y = 2;
    }
    gridCoordinate[0] = x;
    gridCoordinate[1] = y;
};

sf::Vector2f TicTacToeGridSpot::getPostition()
{
    sf::Vector2f position{spot.left, spot.top};
    return position;
}

float TicTacToeGridSpot::getWidth()
{
    return spot.width;
}

float TicTacToeGridSpot::getHeight()
{
    return spot.height;
}

sf::Vector2f TicTacToeGridSpot::getCenterPosition()
{
    auto pos = getPostition();
    pos.x += getWidth() / 2;
    pos.y += getHeight() / 2;
    return pos;
}

int* TicTacToeGridSpot::getGridPosition()
{
    int* x = gridCoordinate;
    return x;
}

bool TicTacToeGridSpot::contains(const sf::Vector2f &other)
{
    return spot.contains(other);
}