#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>
#include "ScoreModel.h"
class ScoreView {
    sf::Text GameStats;
    ScoreModel &sm;
    sf::Font font;
    sf::Text textRevealedFields;
    sf::Text textFlagAndBomb;
    sf::Text valueRevealedFields;
    sf::Text countFlagAndBomb;
    sf::Text textGameMode;
    sf::Text textGameSize;
    sf::Text valueGameMode;
    sf::Text valueGameSize;
    sf::Text tExit;
    sf::RectangleShape Exit;


public:
    ScoreView(ScoreModel &sm);
    void updateView();



    void draw(sf::RenderWindow &win);
};


#endif //UNTITLED2_SCOREVIEW_H
