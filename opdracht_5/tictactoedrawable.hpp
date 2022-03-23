#ifndef TICTACTOEDRAWABLE_HPP
#define TICTACTOEDRAWABLE_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#define TRACE (std::cout << "\n" << __FILE__ << ":" << __LINE__ << " " << std::flush )
class Tictactoedrawable
{
public:
    Tictactoedrawable(sf::RenderWindow& window) : window(window){};
    sf::RenderWindow & window;
    virtual void draw() = 0;
private:

};
#endif //TICTACTOEDRAWABLE_HPP