#include "MinesweeperBoard.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IntroModel.h"
#include <string>
#include <sstream>




MinesweeperBoard::MinesweeperBoard(int width,int height,GameMode GM)
{
    this->width=width;
    this->height=height;
    this->gameMode=GM;



    for(int y=0; y<height; y++)//zeruje pola
    {
        for(int x=0; x<width; x++)
        {
            tab[x][y].hasFlag=0;
            tab[x][y].hasMine=0;
            tab[x][y].isRevealed=0;

        }
    }


    if(gameMode==DEBUG)
    {
        int a;
        if(width<height)a=width;
        if(height<=width)a=height;

        for(int i=0 ; i<a ; i++)
        {
            tab[i][i].hasMine=1;
            tab[i][0].hasMine=1;

        }

        for(int y=0; y<height; y=y+2)
        {
            tab[0][y].hasMine=1;
        }

    }
    gameState=RUNNING;
}

void MinesweeperBoard::updateBoard(int w,int h,int GM)
{   int numberOfMines=0;
    srand(time(NULL));



    this->width=w;
    this->height=h;
    if(GM==1)this->gameMode=EASY;
    if(GM==2)this->gameMode=NORMAL;
    if(GM==3)this->gameMode=HARD;
    if(gameMode==EASY)numberOfMines=(width)*(height)/10; // liczy ile min
    else if (gameMode==NORMAL)numberOfMines=(width+1)*(height+1)/5;
    else if (gameMode==HARD)numberOfMines=(width+1)*(height+1)*3/10;


    if(gameMode!=DEBUG)
    {
        while(numberOfMines>0)
        {
            int x=rand()%width;
            int y=rand()%height;
            if(tab[x][y].hasMine==0)
            {
                tab[x][y].hasMine=1;
                numberOfMines--;
            }

        }
    }
}
void MinesweeperBoard::debug_display() const
{
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            std::cout<<"[";

            if(tab[x][y].hasMine==1)std::cout<<"M";
            else std::cout<<".";

            if(tab[x][y].isRevealed==1)std::cout<<"o";
            else std::cout<<".";

            if(tab[x][y].hasFlag==1)std::cout<<"f";
            else std::cout<<".";

            std::cout<<"]";
        }
        std::cout<<std::endl;
    }

}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}
int MinesweeperBoard::getMineCount()const
{
    int mines=0;
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            if(tab[x][y].hasMine==1)mines++;
        }
    }
    return mines;
}
int MinesweeperBoard::countMines(int x,int y)const
{
    if(x>=width or y>=height)return -1;
    //if(tab[x][y].isRevealed==0)return -1;

    if(tab[x][y].isRevealed==1)
    {
        int bombAround=0;

        if(x==0 and y!=0 and y!=height)
        {
            if(tab[x][y-1].hasMine==1)bombAround++;
            if(tab[x][y+1].hasMine==1)bombAround++;
            if(tab[x+1][y-1].hasMine==1)bombAround++;
            if(tab[x+1][y].hasMine==1)bombAround++;
            if(tab[x+1][y+1].hasMine==1)bombAround++;

        }
        else if(y==0 and x!=0 and x!=width)
        {
            if(tab[x-1][y].hasMine==1)bombAround++;
            if(tab[x-1][y+1].hasMine==1)bombAround++;
            if(tab[x][y+1].hasMine==1)bombAround++;
            if(tab[x+1][y].hasMine==1)bombAround++;
            if(tab[x+1][y+1].hasMine==1)bombAround++;
        }
        else if(x==width and y!=height and y!=0)
        {
            if(tab[x-1][y-1].hasMine==1)bombAround++;
            if(tab[x-1][y].hasMine==1)bombAround++;
            if(tab[x-1][y+1].hasMine==1)bombAround++;
            if(tab[x][y-1].hasMine==1)bombAround++;
            if(tab[x][y+1].hasMine==1)bombAround++;
        }
        else if(y==height and x!=width and x!=0)
        {
            if(tab[x-1][y-1].hasMine==1)bombAround++;
            if(tab[x-1][y].hasMine==1)bombAround++;
            if(tab[x][y-1].hasMine==1)bombAround++;
            if(tab[x+1][y-1].hasMine==1)bombAround++;
            if(tab[x+1][y].hasMine==1)bombAround++;
        }
        else if(x==0 and y==0)
        {
            if(tab[x][y+1].hasMine==1)bombAround++;
            if(tab[x+1][y].hasMine==1)bombAround++;
            if(tab[x+1][y+1].hasMine==1)bombAround++;
        }
        else if(x==width and y==0)
        {
            if(tab[x-1][y].hasMine==1)bombAround++;
            if(tab[x-1][y+1].hasMine==1)bombAround++;
            if(tab[x][y+1].hasMine==1)bombAround++;

        }
        else if(x==width and y==height)
        {
            if(tab[x-1][y-1].hasMine==1)bombAround++;
            if(tab[x-1][y].hasMine==1)bombAround++;
            if(tab[x][y-1].hasMine==1)bombAround++;
        }
        else if(x==0 and y==width)
        {
            if(tab[x][y-1].hasMine==1)bombAround++;
            if(tab[x+1][y-1].hasMine==1)bombAround++;
            if(tab[x+1][y].hasMine==1)bombAround++;
        }
        else
        {

            if(tab[x-1][y-1].hasMine==1)bombAround++;
            if(tab[x-1][y].hasMine==1)bombAround++;
            if(tab[x-1][y+1].hasMine==1)bombAround++;
            if(tab[x][y-1].hasMine==1)bombAround++;
            if(tab[x][y+1].hasMine==1)bombAround++;
            if(tab[x+1][y-1].hasMine==1)bombAround++;
            if(tab[x+1][y].hasMine==1)bombAround++;
            if(tab[x+1][y+1].hasMine==1)bombAround++;

        }
        return bombAround;
    }
}
bool MinesweeperBoard::hasFlag(int x,int y)
{
    if(tab[x][y].hasFlag==1)return true;
    if(x>=width or y>=height) return false;
    if(gameState!=RUNNING)return false;
    if(tab[x][y].isRevealed==1)return false;

}
void MinesweeperBoard::toggleFlag(int x,int y)
{

    if(x>=width or y>=height)return;
    if(tab[x][y].isRevealed==1)return;
    if(gameState!=RUNNING)return;

    if(tab[x][y].isRevealed==0)
    {
        if(tab[x][y].hasFlag==1)
        {
            tab[x][y].hasFlag=0;

        }

        else if(tab[x][y].hasFlag==0)
        {
            tab[x][y].hasFlag=1;

        }

    }
}

    void MinesweeperBoard::revealField(int x,int y)
    {
        if(x>=width or y>=height)return;
        if(tab[x][y].isRevealed==1)return;
        if(gameState!=RUNNING)return;
        if(tab[x][y].hasFlag==1)return;

        if(tab[x][y].hasMine==0)tab[x][y].isRevealed=1;
        if(tab[x][y].hasMine==1)
        {
            int notFirst=0;                 // 0=first move after start game | 1=not first move
            for(int y=0; y<height; y++)
            {
                for(int x=0; x<width; x++)
                {
                    if(tab[x][y].isRevealed==1)notFirst++;
                    if(notFirst>0)break;
                }
                if(notFirst>0)break;
            }

            if(notFirst==1)
            {
                tab[x][y].isRevealed=1;
                gameState=FINISHED_LOSS;
            }

            if(notFirst==0)
            {
                if(gameMode!=DEBUG)
                {
                tab[x][y].hasMine=0;
                int a=rand()%width;
                int b=rand()%height;
                tab[a][b].hasMine=1;
                }
                else tab[x][y].isRevealed=1;
            }
            tab[x][y].isRevealed=1;

        }
        if(countMines(x,y)==0)
        {
            if(x==0 and y!=0 and y!=height)
            {
                if(countMines(x,y-1)==0)revealField(x,y-1);
                if(countMines(x,y+1)==0)revealField(x,y+1);
                if(countMines(x+1,y-1)==0)revealField(x+1,y-1);
                if(countMines(x+1,y)==0)revealField(x+1,y);
                if(countMines(x+1,y+1)==0)revealField(x+1,y+1);

            }
            else if(y==0 and x!=0 and x!=width)
            {
                if(countMines(x-1,y)==0)revealField  (x-1,y);
                if(countMines(x-1,y+1)==0)revealField(x-1,y+1);
                if(countMines(x,y+1)==0)revealField  (x,y+1);
                if(countMines(x+1,y)==0)revealField  (x+1,y);
                if(countMines(x+1,y+1)==0)revealField(x+1,y+1);
            }
            else if(x==width and y!=height and y!=0)
            {   if(countMines(x-1,y-1)==0)revealField(x-1,y-1);
                if(countMines(x-1,y)==0)revealField(x-1,y);
                if(countMines(x-1,y+1)==0)revealField(x-1,y+1);
                if(countMines(x,y-1)==0)revealField(x,y-1);
                if(countMines(x,y+1)==0)revealField(x,y+1);
            }
            else if(y==height and x!=width and x!=0)
            {   if(countMines(x-1,y-1)==0)revealField(x-1,y-1);
                if(countMines(x-1,y)==0)revealField(x-1,y);
                if(countMines(x,y-1)==0)revealField(x,y-1);
                if(countMines(x+1,y-1)==0)revealField(x+1,y-1);
                if(countMines(x+1,y)==0)revealField(x+1,y);
            }
            else if(x==0 and y==0)
            {
                if(countMines(x,y+1)==0)revealField(x,y+1);
                if(countMines(x+1,y)==0)revealField(x+1,y);
                if(countMines(x+1,y+1)==0)revealField(x+1,y+1);

            }
            else if(x==width and y==0)
            {
                if(countMines(x-1,y)==0)revealField(x-1,y);
                if(countMines(x-1,y+1)==0)revealField(x-1,y+1);
                if(countMines(x,y+1)==0)revealField(x,y+1);
            }
            else if(x==width and y==height)
            {
                if(countMines(x-1,y-1)==0)revealField(x-1,y-1);
                if(countMines(x-1,y)==0)revealField(x-1,y);
                if(countMines(x,y-1)==0)revealField(x,y-1);
            }
            else if(x==0 and y==width)
            {
                if(countMines(x,y-1)==0)revealField(x,y-1);
                if(countMines(x+1,y-1)==0)revealField(x+1,y-1);
                if(countMines(x+1,y)==0)revealField(x+1,y);
            }
            else
            {
                if(countMines(x-1,y-1)==0)revealField(x-1,y-1);
                if(countMines(x-1,y)==0)revealField(x-1,y);
                if(countMines(x-1,y+1)==0)revealField(x-1,y+1);
                if(countMines(x,y-1)==0)revealField(x,y-1);
                if(countMines(x,y+1)==0)revealField(x,y+1);
                if(countMines(x+1,y-1)==0)revealField(x+1,y-1);
                if(countMines(x+1,y)==0)revealField(x+1,y);
                if(countMines(x+1,y+1)==0)revealField(x+1,y+1);
            }

        }

    }
    bool MinesweeperBoard::isRevealed(int x,int y)const
    {
        if(tab[x][y].isRevealed==1)return true;
        if(tab[x][y].isRevealed==0)return false;
    }
    GameState MinesweeperBoard::getGameState() const
    {
        for(int y=0; y<height; y++)
        {
            for(int x=0; x<width; x++)
            {
                if(tab[x][y].hasMine==1 and tab[x][y].isRevealed==1)
                {
                    return FINISHED_LOSS;
                }
            }
        }

        bool Win=1;
        for(int y=0; y<height; y++)
        {
            for(int x=0; x<width; x++)
            {
                if(tab[x][y].hasFlag!=tab[x][y].hasMine)Win=0;
                if(Win==0)break;
            }
            if(Win==0)break;
        }
        if(Win==1)
           {
            return FINISHED_WIN;
           }

        Win=1;
        for(int y=0; y<height; y++)
        {
            for(int x=0; x<width; x++)
            {
                if(tab[x][y].isRevealed==tab[x][y].hasMine)Win=0;
                if(Win==0)break;
            }
            if(Win==0)break;
        }
        if(Win==1){
            return FINISHED_WIN;
           }

        return RUNNING;

    }

    char MinesweeperBoard::getFieldInfo(int x, int y) const
    {
        if(x>width or y>height)return'#';
        if(tab[x][y].hasFlag==1 and tab[x][y].isRevealed==0)return'F';
        if(tab[x][y].hasFlag==0 and tab[x][y].isRevealed==0)return'_';
        if(tab[x][y].isRevealed==1 and tab[x][y].hasMine==1)return'x';
        if(tab[x][y].isRevealed==1 and countMines(x,y)==0)return' ';
        if(tab[x][y].isRevealed==1 and countMines(x,y)>0)return countMines(x,y)+48;
    }

std::string MinesweeperBoard::FlagAndBomb() {
    int FlagAndBomb=0;
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            if(tab[x][y].hasFlag==1 and tab[x][y].hasMine==1)FlagAndBomb++;

        }
    }

    std::stringstream ss;
    ss<<FlagAndBomb;
    std::string str = ss.str();

    return str;
}
std::string MinesweeperBoard::RevealedPercent()
{   int RevealedPercent=0;
    double tmp=0;
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {

            if(tab[x][y].isRevealed==1)tmp++;


        }
    }
    RevealedPercent=(tmp/(height*width))*100;
    std::stringstream ss;
    ss<<RevealedPercent;
    std::string str = ss.str();


    return str;
}

GameMode MinesweeperBoard::getGM() {
    return gameMode;
}
