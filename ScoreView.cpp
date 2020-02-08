#include "ScoreView.h"

ScoreView::ScoreView(ScoreModel &sm):sm(sm)
{
    if (!font.loadFromFile("Arial.ttf")) {
        abort();
    }
    GameStats.setFont(font);
    GameStats.setString("Game Stats:");
    GameStats.setPosition(265, 60);
    GameStats.setFillColor(sf::Color(180,180,180,255));
    GameStats.setCharacterSize(50);
    GameStats.setOutlineThickness(2);
    GameStats.setOutlineColor(sf::Color::Black);

    textRevealedFields.setFont(font);
    textRevealedFields.setString("Revealed Fields:");
    textRevealedFields.setPosition(160, 190);
    textRevealedFields.setFillColor(sf::Color(180,180,180,255));
    textRevealedFields.setCharacterSize(35);
    textRevealedFields.setOutlineThickness(2);
    textRevealedFields.setOutlineColor(sf::Color::Black);

    textFlagAndBomb.setFont(font);
    textFlagAndBomb.setString("Flag and Bomb:");
    textFlagAndBomb.setPosition(160, 250);
    textFlagAndBomb.setFillColor(sf::Color(180,180,180,255));
    textFlagAndBomb.setCharacterSize(35);
    textFlagAndBomb.setOutlineThickness(2);
    textFlagAndBomb.setOutlineColor(sf::Color::Black);

    countFlagAndBomb.setFont(font);
    countFlagAndBomb.setPosition(460, 250);
    countFlagAndBomb.setFillColor(sf::Color(180,180,180,255));
    countFlagAndBomb.setCharacterSize(35);
    countFlagAndBomb.setOutlineThickness(2);
    countFlagAndBomb.setOutlineColor(sf::Color::Black);

    valueRevealedFields.setFont(font);
    valueRevealedFields.setPosition(460, 190);
    valueRevealedFields.setFillColor(sf::Color(180,180,180,255));
    valueRevealedFields.setCharacterSize(35);
    valueRevealedFields.setOutlineThickness(2);
    valueRevealedFields.setOutlineColor(sf::Color::Black);

    textGameMode.setFont(font);
    textGameMode.setString("Game Mode:");
    textGameMode.setPosition(160, 320);
    textGameMode.setFillColor(sf::Color(180,180,180));
    textGameMode.setCharacterSize(35);
    textGameMode.setOutlineThickness(2);
    textGameMode.setOutlineColor(sf::Color::Black);


    textGameSize.setFont(font);
    textGameSize.setString("Game Size:");
    textGameSize.setPosition(160, 390);
    textGameSize.setFillColor(sf::Color(180,180,180));
    textGameSize.setCharacterSize(35);
    textGameSize.setOutlineThickness(2);
    textGameSize.setOutlineColor(sf::Color::Black);

    valueGameMode.setFont(font);
    valueGameMode.setPosition(460, 320);
    valueGameMode.setFillColor(sf::Color(180,180,180,255));
    valueGameMode.setCharacterSize(35);
    valueGameMode.setOutlineThickness(2);
    valueGameMode.setOutlineColor(sf::Color::Black);

    valueGameSize.setFont(font);
    valueGameSize.setPosition(460, 390);
    valueGameSize.setFillColor(sf::Color(180,180,180,255));
    valueGameSize.setCharacterSize(35);
    valueGameSize.setOutlineThickness(2);
    valueGameSize.setOutlineColor(sf::Color::Black);

    Exit.setOutlineColor(sf::Color::Black);
    Exit.setPosition(650,540);
    Exit.setFillColor(sf::Color(180,180,180,255));
    Exit.setOutlineThickness(2);
    Exit.setSize(sf::Vector2f(110,50));
    tExit.setPosition(670,545);
    tExit.setString("EXIT");
    tExit.setCharacterSize(30);
    tExit.setFont(font);
    tExit.setFillColor(sf::Color(144,144,144,255));
    tExit.setOutlineThickness(2);
    tExit.setOutlineColor(sf::Color::Black);

}


void ScoreView::draw(sf::RenderWindow &win) {
    win.draw(GameStats);
    countFlagAndBomb.setString(sm.getFlagAndBomb());
    valueRevealedFields.setString(sm.getRevealedPercent()+" %");
    valueGameSize.setString(sm.getGameSize());
    valueGameMode.setString(sm.getGameMode());
    win.draw(textFlagAndBomb);
    win.draw(textRevealedFields);
    win.draw(countFlagAndBomb);
    win.draw(valueRevealedFields);
    win.draw(textGameSize);
    win.draw(textGameMode);
    win.draw(valueGameMode);
    win.draw(valueGameSize);
    win.draw(Exit);
    win.draw(tExit);
}