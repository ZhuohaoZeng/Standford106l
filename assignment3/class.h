
class creature{
    public:
        creature(float curHp, float maxHp);
        void setCurHp(float curHp);
        void setMaxHp(float maxHp);
        void setCreature(bool Creature);
        float getCurHp() const;
        float getMaxHp() const;
        
    protected:
        float curHp;
        float maxHp;
        float differenceHp;
        virtual void setDifferenceHp() = 0;
    private:
        bool Creature;

};

class Goblin: public creature{
    public:
        Goblin(float curHp, float maxHp);
    private:
        void setDifferenceHp() override;
};