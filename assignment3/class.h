
class creature{
    public:
        creature(float curHp, float maxHp);
        virtual void setCurHp(float curHp) = 0;
        virtual void setMaxHp(float maxHp) = 0;
        virtual float getCurHp() const = 0;
        virtual float getMaxHp() const = 0;
        float curHp;
        float maxHp;
        float differenceHp;
        
    private:
        
        virtual void SetDifferenceHp() = 0;
};

class Goblin: public creature{
    Goblin(float curHp, float maxHp) : creature(curHp, maxHp) {};
};