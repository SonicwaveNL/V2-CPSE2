#ifndef TICTACTOEGRID_HPP
#define TICTACTOEGRID_HPP
#include "tictactoedrawable.hpp"
#include "tictactoegridspot.hpp"
class TicTacToeGrid : public Tictactoedrawable
{
public:
    TicTacToeGrid(sf::RenderWindow &window);
    TicTacToeGridSpot *gridSpotArray[9];
    void draw() override;

private:
    sf::RectangleShape verticalWall1;
    sf::RectangleShape verticalWall2;
    sf::RectangleShape horizontalWall1;
    sf::RectangleShape horizontalWall2;
    sf::Vector2f wallSize{640, 20};
    sf::Vector2f horizontalWallStartPos{0, 146};
    sf::Vector2f verticalWallStartPos{200, 0};
    sf::Color wallColor = sf::Color::Black;

    float gridSpotx = verticalWallStartPos.x + wallSize.y;
    float gridSpoty = horizontalWallStartPos.y + wallSize.y;
    TicTacToeGridSpot spot00{sf::Vector2f(0, 0)};
    TicTacToeGridSpot spot10{sf::Vector2f(gridSpotx, 0)};
    TicTacToeGridSpot spot20{sf::Vector2f(gridSpotx * 2, 0)};
    TicTacToeGridSpot spot01{sf::Vector2f(0, gridSpoty)};
    TicTacToeGridSpot spot11{sf::Vector2f(gridSpotx, gridSpoty)};
    TicTacToeGridSpot spot21{sf::Vector2f(gridSpotx * 2, gridSpoty)};
    TicTacToeGridSpot spot02{sf::Vector2f(0, gridSpoty * 2)};
    TicTacToeGridSpot spot12{sf::Vector2f(gridSpotx, gridSpoty * 2)};
    TicTacToeGridSpot spot22{sf::Vector2f{gridSpotx * 2, gridSpoty * 2}};
};
#endif //TICTACTOEGRID_HPP