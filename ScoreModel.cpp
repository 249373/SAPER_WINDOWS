//
// Created by konrad on 14.04.19.
//

#include "ScoreModel.h"

ScoreModel::ScoreModel (MinesweeperBoard &board):board(board)
{}
void ScoreModel::updateModel()
{
    RevealedPercent=board.RevealedPercent();
    FlagAndBomb=board.FlagAndBomb();
    gameMode=board.getGM();
    height=board.getBoardHeight();

}
std::string ScoreModel::getRevealedPercent() {return RevealedPercent;}
std::string ScoreModel::getFlagAndBomb() {return FlagAndBomb;}

std::string ScoreModel::getGameMode()
{
    if(gameMode==EASY)return"EASY";
    if(gameMode==NORMAL)return"NORMAL";
    if(gameMode==HARD)return"HARD";
}

std::string ScoreModel::getGameSize()
{
if(height==10)return"10x10";
if(height==15)return"20x15";
if(height==20)return"30x20";
}
