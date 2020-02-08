#include <SFML/Graphics.hpp>
#include "ScoreController.h"
#include "ScoreView.h"
#include "IntroController.h"
#include "IntroView.h"
#include "MinesweeperController.h"
#include "MinesweeperView.h"
#include "ScoreModel.h"
#include "GameManager.h"
#include "IntroModel.h"


int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel=16;
    sf::RenderWindow win(sf::VideoMode(800, 600), "SFML window",sf::Style::Default,settings);


    IntroModel im;
    IntroView iv(im);
    MinesweeperBoard board(20,10,EASY);
    MinesweeperView mv(board,23,10,10);
    ScoreModel sm(board);
    ScoreView sv(sm);

    ScoreController sc(sv);
    MinesweeperController mc(mv,board,sm);
    IntroController ic(iv,im,board);



    GameManager gm(ic, mc, sc);


    // Start the game loop
    while (win.isOpen()) {
        // Process events
        sf::Event event;
        while (win.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                win.close();
            if(gm.getState()==true)
                win.close();
            gm.handleEvent(event);
        }

        // Clear screen
        win.clear(sf::Color(144,144,144,255));

        // Draw current state
        gm.draw(win);

        // Update the window
        win.display();
    }

    return EXIT_SUCCESS;
}