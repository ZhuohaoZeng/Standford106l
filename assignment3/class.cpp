#include "class.h"

Goblin::Goblin(float curHp, float maxHp){
    this->curHp = curHp;
    this->maxHp = maxHp;
    Goblin::SetDifferenceHp();
}

float creature::getCurHp() const{
    return this->curHp;
};

void creature::setCurHp(float curHp){
    this->curHp = curHp;
};

float creature::getMaxHp() const{
    return this->maxHp;
};

void creature::setMaxHp(float maxHp){
    this->maxHp = maxHp;
}

void creature::SetDifferenceHp(){
    this->differenceHp = maxHp - curHp;
}