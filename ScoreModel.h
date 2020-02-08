//
// Created by konrad on 14.04.19.
//

#ifndef UNTITLED2_SCOREMODEL_H
#define UNTITLED2_SCOREMODEL_H


#include <SFML/Graphics/Text.hpp>
#include "MinesweeperBoard.h"

class ScoreModel {
    MinesweeperBoard &board;
    std::string FlagAndBomb ;
    std::string RevealedPercent;
    GameMode gameMode;
    int height;
public:
    ScoreModel(MinesweeperBoard &board);
    void updateModel();
    std::string getRevealedPercent();
    std::string  getFlagAndBomb();
    std::string getGameMode();
    std::string getGameSize();

};


#endif //UNTITLED2_SCOREMODEL_H
