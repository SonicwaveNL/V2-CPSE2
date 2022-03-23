#ifndef TICTACTOEGRIDSPOT_HPP
#define TICTACTOEGRIDSPOT_HPP
#include <SFML/Graphics.hpp>
class TicTacToeGridSpot
{
public:
    TicTacToeGridSpot(const sf::Vector2f &position);
    sf::Vector2f getPostition();
    float getWidth();
    float getHeight();
    sf::Vector2f getCenterPosition();
    int* getGridPosition();
    bool contains(const sf::Vector2f &other);

private:
    sf::FloatRect spot;
    int gridCoordinate[2];
};
#endif //TICTACTOEGRIDSPOT_HPP