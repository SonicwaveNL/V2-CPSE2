#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "tictactoedrawable.hpp"
class Circle : public Tictactoedrawable
{
public:
    Circle(sf::RenderWindow &window, sf::Vector2f position) : Tictactoedrawable(window)
    {
        circle.setPosition(sf::Vector2f(position.x - 40, position.y - 40));
        circle.setRadius(40);
        circle.setFillColor(sf::Color::Blue);
    };
    void draw() override;
    const std::string name = "circle";
private:
    sf::CircleShape circle;
};
#endif //CIRCLE_HPP