//
// Created by konrad on 10.04.19.
//
#include<iostream>
#include "IntroModel.h"

int IntroModel::getgm()
{
    return gm;
}

int IntroModel::getgs()
{
    return gs;
}

int IntroModel::gety()
{
    if(gs==1) return 10;
    if(gs==2) return 15;
    if(gs==3) return 20;
}

int IntroModel::getx()
{
    if(gs==1) return 10;
    if(gs==2) return 20;
    if(gs==3) return 30;
}


void IntroModel::updateModel(int a)
{
    if(a==1)gm=1;
    if(a==2)gm=2;
    if(a==3)gm=3;
    if(a==4)gs=1;
    if(a==5)gs=2;
    if(a==6)gs=3;


}
