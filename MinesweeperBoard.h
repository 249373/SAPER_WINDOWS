#ifndef MINESWEEPERBOARD_H_INCLUDED
#define MINESWEEPERBOARD_H_INCLUDED

#include <iostream>

struct Field
{
    bool hasMine=0;
    bool hasFlag=0;
    bool isRevealed=0;
};


enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};


class MinesweeperBoard
{
    Field tab[100][100];
    int width;
    int height;
    GameMode gameMode;
    GameState gameState;


public:
    MinesweeperBoard(int,int,GameMode);
    int getBoardWidth()const;
    int getBoardHeight()const;
    int getMineCount()const;
    int countMines(int,int)const;
    bool hasFlag(int,int);
    void toggleFlag(int,int);
    void revealField(int,int);
    bool isRevealed(int,int)const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;
    void updateBoard(int,int,int);
    std::string FlagAndBomb();
    std::string RevealedPercent();
    GameMode getGM();


    void debug_display()const;
}    ;

#endif // MINESWEEPERBOARD_H_INCLUDED
