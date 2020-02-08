#include "IntroView.h"
#include <cstdlib> // abort()

IntroView::IntroView(IntroModel &im):im(im) {



    if (!font.loadFromFile("Arial.ttf")) {
        abort();
    }
    saper.setFont(font);
    saper.setString("SAPER");
    saper.setPosition(315, 40);
    saper.setFillColor(sf::Color(180,180,180,255));
    saper.setCharacterSize(50);
    saper.setOutlineThickness(2);
    saper.setOutlineColor(sf::Color::Black);

    name.setFont(font);
    name.setString("Konrad Pazgan");
    name.setPosition(305, 110);
    name.setFillColor(sf::Color(180,180,180,255));
    name.setCharacterSize(25);
    name.setOutlineThickness(1);
    name.setOutlineColor(sf::Color::Black);

    number.setFont(font);
    number.setString("Nr: 249373");
    number.setPosition(285, 145);
    number.setFillColor(sf::Color(180,180,180,255));
    number.setCharacterSize(15);
    number.setOutlineThickness(1);
    number.setOutlineColor(sf::Color::Black);

    group.setFont(font);
    group.setString("grupa: Wt-15.15");
    group.setPosition(395, 145);
    group.setFillColor(sf::Color(180,180,180,255));
    group.setCharacterSize(15);
    group.setOutlineThickness(1);
    group.setOutlineColor(sf::Color::Black);


}
void IntroView::draw(sf::RenderWindow &win) {

    levelE.setSize(sf::Vector2f(180, 80));
    levelE.setPosition(63,190);
    levelN.setSize(sf::Vector2f(180, 80));
    levelN.setPosition(303,190);
    levelH.setSize(sf::Vector2f(180, 80));
    levelH.setPosition(543,190);
    levelE.setOutlineThickness(5);
    levelN.setOutlineThickness(5);
    levelH.setOutlineThickness(5);

    TlevelE.setFont(font);
    TlevelE.setString("EASY");
    TlevelE.setPosition(108,208);
    TlevelE.setFillColor(sf::Color::Black);
    TlevelE.setCharacterSize(35);
    TlevelN.setFont(font);
    TlevelN.setString("NORMAL");
    TlevelN.setPosition(316,208);
    TlevelN.setFillColor(sf::Color::Black);
    TlevelN.setCharacterSize(35);
    TlevelH.setFont(font);
    TlevelH.setString("HARD");
    TlevelH.setPosition(583,208);
    TlevelH.setFillColor(sf::Color::Black);
    TlevelH.setCharacterSize(35);

    size10.setSize(sf::Vector2f(180, 80));
    size10.setPosition(63,350);
    size20.setSize(sf::Vector2f(180, 80));
    size20.setPosition(303,350);
    size30.setSize(sf::Vector2f(180, 80));
    size30.setPosition(543,350);
    size10.setOutlineThickness(5);
    size20.setOutlineThickness(5);
    size30.setOutlineThickness(5);

    T10.setFont(font);
    T10.setString("10x10");
    T10.setPosition(103,365);
    T10.setFillColor(sf::Color::Black);
    T10.setCharacterSize(35);
    T20.setFont(font);
    T20.setString("20x15");
    T20.setPosition(343,365);
    T20.setFillColor(sf::Color::Black);
    T20.setCharacterSize(35);
    T30.setFont(font);
    T30.setString("30x20");
    T30.setPosition(588,365);
    T30.setFillColor(sf::Color::Black);
    T30.setCharacterSize(35);

    start.setFillColor(sf::Color::Black);
    start.setRadius(50);
    start.setPosition(650,520);
    start.setOrigin(50,50);


    start1.setFillColor(sf::Color::Black);
    start1.setPosition(650,520);
    start1.setSize(sf::Vector2f(20,120));
    start1.setOrigin(10,60);

    start2.setFillColor(sf::Color::Black);
    start2.setPosition(650,520);
    start2.setSize(sf::Vector2f(20,120));
    start2.setOrigin(10,60);
    start2.setRotation(45);

    start3.setFillColor(sf::Color::Black);
    start3.setPosition(650,520);
    start3.setSize(sf::Vector2f(20,120));
    start3.setOrigin(10,60);
    start3.setRotation(90);

    start0.setFillColor(sf::Color::Black);
    start0.setPosition(650,520);
    start0.setSize(sf::Vector2f(20,120));
    start0.setOrigin(10,60);
    start0.setRotation(135);

    Tstart.setFillColor(sf::Color::White);
    Tstart.setPosition(618,507);
    Tstart.setCharacterSize(20);
    Tstart.setFont(font);
    Tstart.setString("START");

    if(im.getgm()==1)//EASY
    {   levelE.setFillColor(sf::Color(70,195,70,255));
        levelE.setOutlineColor(sf::Color::Black);
    }
    else
        {levelE.setFillColor(sf::Color(180,180,180,255));
        levelE.setOutlineColor(sf::Color::Black);
    }
    if(im.getgm()==2)//NORM
    {   levelN.setFillColor(sf::Color(255,215,75,255));
        levelN.setOutlineColor(sf::Color::Black);
    }
    else
    {   levelN.setFillColor(sf::Color(180,180,180,255));
        levelN.setOutlineColor(sf::Color::Black);
    }
    if(im.getgm()==3)//HARD
    {   levelH.setFillColor(sf::Color(215,50,50,255));
        levelH.setOutlineColor(sf::Color::Black);
    }
    else
    {   levelH.setFillColor(sf::Color(180,180,180,255));
        levelH.setOutlineColor(sf::Color::Black);
    }
    if(im.getgs()==1)
    {    size10.setOutlineColor(sf::Color::Black);
        size10.setFillColor(sf::Color(50,50,215,255));
    }
    else
    {    size10.setOutlineColor(sf::Color::Black);
        size10.setFillColor(sf::Color(180,180,180,255));
    }
    if(im.getgs()==2)
    {   size20.setOutlineColor(sf::Color::Black);
        size20.setFillColor(sf::Color(50,50,215,255));
    }
    else
    {   size20.setOutlineColor(sf::Color::Black);
        size20.setFillColor(sf::Color(180,180,180,255));
    }
    if(im.getgs()==3)
    {   size30.setOutlineColor(sf::Color::Black);
        size30.setFillColor(sf::Color(50,50,215,255));
    }
    else
    {   size30.setOutlineColor(sf::Color::Black);
        size30.setFillColor(sf::Color(180,180,180,255));
    }

    win.draw(saper);
    win.draw(name);
    win. draw(levelE);
    win. draw(levelH);
    win. draw(levelN);
    win.draw(size20);
    win.draw(size10);
    win.draw(size30);
    win.draw(TlevelE);
    win.draw(TlevelN);
    win.draw(TlevelH);
    win.draw(T10);
    win.draw(T20);
    win.draw(T30);
    win.draw(start);
    win.draw(start0);
    win.draw(start1);
    win.draw(start2);
    win.draw(start3);
    win.draw(Tstart);
    win.draw(group);
    win.draw(number);


}