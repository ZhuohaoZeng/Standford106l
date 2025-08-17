#include "class.h"

creature::creature (float curHp, float maxHp){
    this->curHp = curHp;
    this->maxHp = maxHp;
}

Goblin::Goblin (float curHp, float maxHp):
        creature(curHp, maxHp) {
    this->curHp = curHp;
    this->maxHp = maxHp;
    Goblin::setDifferenceHp();
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

void Goblin::setDifferenceHp(){
    this->differenceHp = maxHp - curHp;
}

void creature::setCreature(bool isCreature){
    this->Creature = isCreature;
}