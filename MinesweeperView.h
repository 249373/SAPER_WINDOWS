//
// Created by konrad on 02.04.19.
//

#ifndef SAPPERRO_MSSFMLVIEW_H
#define SAPPERRO_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"


class MinesweeperView {
    sf::Color Revealed;
    sf::Color NotRevealed;
    sf::RectangleShape flagLane;
    sf::RectangleShape Field;
    sf::ConvexShape flagTriangle;
    sf::Font Arial;
    sf::Text text;
    sf::CircleShape bombCircle;
    sf::RectangleShape bombLane1;
    sf::RectangleShape bombLane2;
    sf::RectangleShape bombLane3;
    sf::RectangleShape bombLane4;
    sf::Text Loss;
    sf::Text Win;
    sf::RectangleShape rectStats;
    sf::Text textStats;


    void updateFlag(int,int);
    void updateText(int,int);
    void updateBomb(int,int);

    MinesweeperBoard & board;

public:
     int row;        //count ract
     int poem;       //count ract
     const int x0;      // first ract position
     const int y0;      // first ract position
     const int size;    //ract size
     const int space=3;    //between ract
    MinesweeperView(MinesweeperBoard & board,int,int,int);  //board,size,x0,y0

    void draw(sf::RenderWindow & win);
};


#endif //SAPPERRO_MSSFMLVIEW_H
