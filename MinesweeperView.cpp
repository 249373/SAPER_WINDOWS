//
// Created by konrad on 02.04.19.
//
#include "MinesweeperBoard.h"
#include "MinesweeperView.h"
#include <iostream>
#include "MinesweeperView.h"


MinesweeperView::MinesweeperView(MinesweeperBoard & board,int size,int x0,int y0)
:board(board),size(size), x0(x0), y0(y0)
{    if (!Arial.loadFromFile("Arial.ttf"))
    {}

    poem=board.getBoardHeight();
    row=board.getBoardWidth();

    NotRevealed=sf::Color(180,180,180,255);
    Revealed=sf::Color(200,255,255,255);
    Field.setSize(sf::Vector2f(size, size));
    Field.setOutlineColor(sf::Color::Black);
    Field.setOutlineThickness(1);
    flagLane.setSize(sf::Vector2f(size/20,size*0.6));

    Win.setFont(Arial);
    Win.setCharacterSize(50);
    Win.setFillColor(sf::Color(70,195,70,255));
    Win.setPosition(250,530);
    Win.setString("YOU WIN");
    Win.setOutlineColor(sf::Color::Black);
    Win.setOutlineThickness(1);
    Loss.setFont(Arial);
    Loss.setCharacterSize(50);
    Loss.setFillColor(sf::Color(215,50,50,255));
    Loss.setPosition(250,530);
    Loss.setString("GAME OVER");
    Loss.setOutlineColor(sf::Color::Black);
    Loss.setOutlineThickness(1);

    rectStats.setOutlineColor(sf::Color::Black);
    rectStats.setPosition(650,540);
    rectStats.setFillColor(sf::Color(180,180,180,255));
    rectStats.setOutlineThickness(2);
    rectStats.setSize(sf::Vector2f(110,50));
    textStats.setPosition(659,545);
    textStats.setString("STATS");
    textStats.setCharacterSize(30);
    textStats.setFont(Arial);
    textStats.setFillColor(sf::Color(144,144,144,255));
    textStats.setOutlineThickness(2);
    textStats.setOutlineColor(sf::Color::Black);


}
void MinesweeperView::updateFlag(int x,int y)
{
    flagTriangle.setPointCount(3);

// define the points
    flagTriangle.setPoint(0, sf::Vector2f(x0+space*x+x*size+(2*size/5),y0+space*y+y*size+(size/4)));
    flagTriangle.setPoint(1, sf::Vector2f(x0+space*x+x*size+(4*size/5),y0+space*y+y*size+(size/2)));
    flagTriangle.setPoint(2, sf::Vector2f(x0+space*x+x*size+(2*size/5), y0+space*y+y*size+(2*size/3)));
    flagTriangle.setFillColor(sf::Color::Red);
    flagLane.setPosition(x0+space*x+x*size+(2*size/5),y0+space*y+y*size+(size/4));
    flagLane.setFillColor(sf::Color::Black);
}

void MinesweeperView::updateBomb(int x, int y)
{   bombCircle.setOrigin(size/3,size/3);
    bombCircle.setPosition(x0+space*x+x*size+size/2,y0+space*y+y*size+size/2);
    bombCircle.setFillColor(sf::Color::Black);
    bombCircle.setRadius(size/3);


    bombLane1.setPosition(sf::Vector2f(x0+space*x+x*size+size/2,y0+space*y+y*size+size/2));
    bombLane1.setFillColor(sf::Color::Black);
    bombLane1.setSize(sf::Vector2f(size/7,size*4/5));
    bombLane1.setOrigin(size/14,size*4/10);

    bombLane2.setPosition(sf::Vector2f(x0+space*x+x*size+size/2,y0+space*y+y*size+size/2));
    bombLane2.setFillColor(sf::Color::Black);
    bombLane2.setSize(sf::Vector2f(size/7,size*4/5));
    bombLane2.setRotation(90);
    bombLane2.setOrigin(size/14,size*4/10);

    bombLane3.setPosition(sf::Vector2f(x0+space*x+x*size+size/2,y0+space*y+y*size+size/2));
    bombLane3.setFillColor(sf::Color::Black);
    bombLane3.setSize(sf::Vector2f(size/7,size*4/5));
    bombLane3.setRotation(45);
    bombLane3.setOrigin(size/14,size*4/10);

    bombLane4.setPosition(sf::Vector2f(x0+space*x+x*size+size/2,y0+space*y+y*size+size/2));
    bombLane4.setFillColor(sf::Color::Black);
    bombLane4.setSize(sf::Vector2f(size/7,size*4/5));
    bombLane4.setRotation(135);
    bombLane4.setOrigin(size/14,size*4/10);



}
void MinesweeperView::updateText(int x, int y) {
    text.setFillColor(sf::Color::Black);
    text.setFont(Arial);
    text.setPosition(x0+space*x+x*size+size/4,y0+space*y+y*size-size/8);
    text.setCharacterSize(size);
    text.setString(board.getFieldInfo(x,y));
}

void MinesweeperView::draw(sf::RenderWindow & win)
{
    for(int y=0 ; y<board.getBoardHeight() ; y++)
    {
        for(int x=0 ; x<board.getBoardWidth() ; x++ )
        {   Field.setPosition(x0+space*x+x*size,y0+space*y+y*size);

            if(board.getFieldInfo(x,y)=='_')
            {
                Field.setFillColor(NotRevealed);
                win.draw(Field);
            }
            if(board.getFieldInfo(x,y)=='F')
            {
                Field.setFillColor(NotRevealed);
                win.draw(Field);
                updateFlag(x,y);
                win.draw(flagLane);
                win.draw(flagTriangle);
            }
            if(board.getFieldInfo(x,y)=='x')
            {
                Field.setFillColor(sf::Color::Red);
                win.draw(Field);
                updateBomb(x,y);
                win.draw(bombCircle);
                win.draw(bombLane1);
                win.draw(bombLane2);
                win.draw(bombLane3);
                win.draw(bombLane4);

            }
            if(board.getFieldInfo(x,y)==' ')
            {
                Field.setFillColor(Revealed);
                win.draw(Field);
            }
            if(48<(int)board.getFieldInfo(x,y)and (int)board.getFieldInfo(x,y)<58)
            {
                Field.setFillColor(Revealed);
                win.draw(Field);
                updateText(x,y);
                win.draw(text);

            }
            if(board.getGameState()==FINISHED_LOSS or board.getGameState()==FINISHED_WIN)
            {
                if(board.getGameState()==FINISHED_LOSS)
                {
                    win.draw(Loss);
                    win.draw(rectStats);
                    win.draw(textStats);
                }
                if(board.getGameState()==FINISHED_WIN)
                {
                     win.draw(Win);
                    win.draw(rectStats);
                    win.draw(textStats);
                }
            }
        }
    }

}



