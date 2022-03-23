#ifndef CROSS_HPP
#define CROSS_HPP
#include "tictactoedrawable.hpp"
#include <math.h>
class Cross : public Tictactoedrawable
{
public:
    Cross(sf::RenderWindow &window, sf::Vector2f position) : Tictactoedrawable(window),
                                                             rectangle1(rectangleSize),
                                                             rectangle2(rectangleSize)
    {
        auto shift = rectangleSize.y / sqrt(2.f) / 2;
        sf::Vector2f rectangle2Pos(position.x + shift, position.y - shift);
        sf::Vector2f rectangle1Pos(position.x - shift, position.y - shift);
        rectangle1.rotate(-45.f);
        rectangle2.rotate(45.f);
        rectangle1.setPosition(rectangle1Pos);
        rectangle2.setPosition(rectangle2Pos);
        rectangle1.setFillColor(sf::Color::Red);
        rectangle2.setFillColor(sf::Color::Red);
        draw();
    };
    void draw() override;
    const std::string name = "cross";
private:
    const sf::Vector2f rectangleSize{5.0f, 120.0f};
    sf::RectangleShape rectangle1;
    sf::RectangleShape rectangle2;
};
#endif //CROSS_HPP