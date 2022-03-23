#include "tictactoegrid.hpp"
#include "bigdrawer.hpp"
#include "cursor.hpp"
#include "coutdrawer.hpp"
#include <iostream>

int main(void)
{
    sf::RenderWindow window{sf::VideoMode{640, 480}, "tic tac toe"};
    TicTacToeGrid grid(window);
    Cursor cursor(window);
    auto game = Game();
    BigDrawer drawer(window, game, grid);

    window.clear(sf::Color::White);
    while (window.isOpen())
    {
        cursor.command(game, grid);
        game.command();
        window.clear(sf::Color::White);
        grid.draw();
        drawer.draw();
        window.display();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            sf::sleep(sf::milliseconds(5));
        }
    }
    game.clearMoves();
    game.gameWon = false;
    coutDrawer couter(game);
    while (true)
    {
        couter.coutGame();
    }
}
