#include "MinesweeperController.h"
#include <iostream>

MinesweeperController::MinesweeperController(MinesweeperView &v, MinesweeperBoard &board, ScoreModel &sm) :view(v), board(board),sm(sm)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {

        int wiersz = (event.mouseButton.y-view.y0)/(view.space+view.size);
        int kolumna = (event.mouseButton.x-view.x0)/(view.space+view.size);

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            board.revealField(kolumna, wiersz); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
            if(board.getGameState()!=RUNNING
                and event.mouseButton.y<590
                and event.mouseButton.y>540
                and event.mouseButton.x<760
                and event.mouseButton.x>650)
                finished = true;
                sm.updateModel();


        }
        else if (event.mouseButton.button == sf::Mouse::Right)
        {
            board.toggleFlag(kolumna, wiersz); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
        }
    }





}