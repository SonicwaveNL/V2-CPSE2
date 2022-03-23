#ifndef CURSOR_HPP
#define CURSOR_HPP
#include "tictactoegrid.hpp"
#include "game.hpp"
class Cursor
{
public:
    Cursor(sf::RenderWindow &window) : window(window){};
    void command(Game& game,TicTacToeGrid & grid);

private:
    sf::RenderWindow &window;
    sf::Mouse cursor;
    sf::Vector2f from_vectorI_to_vectorf(const sf::Vector2i &rhs);
};
#endif //CURSOR_HPP