#include "IntroController.h"
#include <iostream>
#include "MinesweeperBoard.h"

IntroController::IntroController(IntroView &v, IntroModel &m, MinesweeperBoard &board) : view(v),model(m),board(board)
{}

void IntroController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
            int y = event.mouseButton.y;
            int x = event.mouseButton.x;



            if (190 < y and y < 270)//gm
            {
                if (63 < x and x < 243)//E
                {
                   tmp=1;
                }
                if (303 < x and x < 483)//N
                {
                    tmp=2;
                }
                if (543 < x and x < 723)//M
                {
                    tmp=3;
                }


            }
            if (350 < y and y < 430)//gs
            {
                if (63 < x and x < 243)//S
                {
                    tmp=4;
                }
                if (303 < x and x < 483)//M
                {
                    tmp=5;
                }
                if (543 < x and x < 723)//B
                {
                    tmp=6;
                }
            }

            if(50*50>(x-650)*(x-650)+(y-520)*(y-520)) {
            if (model.getgm()!=0 and model.getgs()!=0)
                 {
                finished = true;
                board.updateBoard(model.getx(), model.gety(), model.getgm());
                 }
             }


            if (event.mouseButton.button == sf::Mouse::Left) {
                model.updateModel(tmp);
            }

    }
}