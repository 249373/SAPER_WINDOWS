#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"
#include "ScoreModel.h"
class MinesweeperController {
    bool finished = false;

    MinesweeperView & view;
    MinesweeperBoard & board;
    ScoreModel & sm;
public:
    explicit MinesweeperController(MinesweeperView & v, MinesweeperBoard &board, ScoreModel & sm);

    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};



#endif // MINESWEEPERCONTROLLER_H
