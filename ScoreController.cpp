#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v) : view(v)
{}

void ScoreController::handleEvent(sf::Event &event) {
     if (event.type == sf::Event::MouseButtonPressed)
    {

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if(event.mouseButton.y<590
               and event.mouseButton.y>540
               and event.mouseButton.x<760
               and event.mouseButton.x>650)
                finished = true;

        }

    }
}