#include "tictactoegrid.hpp"

TicTacToeGrid::TicTacToeGrid(sf::RenderWindow &window) : Tictactoedrawable(window)
{
    verticalWall1.setSize(sf::Vector2f(wallSize.y, wallSize.x));
    verticalWall2.setSize(sf::Vector2f(wallSize.y, wallSize.x));
    horizontalWall1.setSize(wallSize);
    horizontalWall2.setSize(wallSize);

    verticalWall1.setFillColor(wallColor);
    verticalWall2.setFillColor(wallColor);
    horizontalWall1.setFillColor(wallColor);
    horizontalWall2.setFillColor(wallColor);

    verticalWall1.setPosition(verticalWallStartPos);
    verticalWall2.setPosition(sf::Vector2f(verticalWallStartPos.x * 2, verticalWallStartPos.y));
    horizontalWall1.setPosition(horizontalWallStartPos);
    horizontalWall2.setPosition(sf::Vector2f(horizontalWallStartPos.x, (horizontalWallStartPos.y * 2) + wallSize.y));

    gridSpotArray[0] = &spot00;
    gridSpotArray[1] = &spot10;
    gridSpotArray[2] = &spot20;
    gridSpotArray[3] = &spot01;
    gridSpotArray[4] = &spot11;
    gridSpotArray[5] = &spot21;
    gridSpotArray[6] = &spot02;
    gridSpotArray[7] = &spot12;
    gridSpotArray[8] = &spot22;
};
void TicTacToeGrid::draw()
{
    window.draw(verticalWall1);
    window.draw(verticalWall2);
    window.draw(horizontalWall1);
    window.draw(horizontalWall2);
}