//
// Created by konrad on 10.04.19.
//

#ifndef UNTITLED2_INTROMODEL_H
#define UNTITLED2_INTROMODEL_H



class IntroModel {
    int gm=0;//0=Debug,1=EASY,2=NORMAL,3=HARD
    int gs=0;  //1=Small.2=Medium,3=Big


    public:
    int getx();
    int gety();
    int getgm();
    int getgs();
    void updateModel(int);


};


#endif //UNTITLED2_INTROMODEL_H
