#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>
#include "IntroModel.h"

class IntroView {
    sf::Font font;
    sf::Text saper;
    sf::Text name;
    sf::RectangleShape levelN;
    sf::RectangleShape levelE;
    sf::RectangleShape levelH;
    sf::RectangleShape size10;
    sf::RectangleShape size20;
    sf::RectangleShape size30;
    sf::Text TlevelE;
    sf::Text TlevelN;
    sf::Text TlevelH;
    sf::Text T10;
    sf::Text T20;
    sf::Text T30;
    sf::Text Tstart;
    IntroModel &im;
    sf::RectangleShape start0;
    sf::RectangleShape start1;
    sf::RectangleShape start2;
    sf::RectangleShape start3;
    sf::CircleShape start;
    sf::Text number;
    sf::Text group;




public:
    IntroView(IntroModel &im);

    void draw(sf::RenderWindow &win);
};


#endif // INTROVIEW_H
