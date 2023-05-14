/*******************************************************
游戏设计V1：设计怪物，亡灵类怪物，元素类怪物，机械类怪物
*******************************************************/
#include <iostream>
class Monster {
protected:
    int m_life;
    int m_magic;
    int m_attack;

public:
    Monster(int life, int magic, int attack)
        : m_life(life)
        , m_magic(magic)
        , m_attack(attack)
    {
    }
    virtual ~Monster() { }
};

class M_Undead : public Monster {
private:
    /* data */
public:
    M_Undead(int life, int magic, int attack)
        : Monster(life, magic, attack)
    {
        std::cout << "一只亡灵怪物来到世界" << std::endl;
    }
    ~M_Undead() { }
};

class M_Element : public Monster {
private:
    /* data */
public:
    M_Element(int life, int magic, int attack)
        : Monster(life, magic, attack)
    {
        std::cout << "一只元素怪物来到世界" << std::endl;
    }
    ~M_Element() { }
};

class M_Mechanic : public Monster {
private:
    /* data */
public:
    M_Mechanic(int life, int magic, int attack)
        : Monster(life, magic, attack)
    {
        std::cout << "一只机械怪物来到世界" << std::endl;
    }
    ~M_Mechanic() { }
};

int main()
{
    M_Undead* pM1 = new M_Undead(300, 50, 80);
    M_Element* pM2 = new M_Element(200, 40, 90);
    M_Mechanic* pM3 = new M_Mechanic(500, 10, 20);

    delete pM1;
    delete pM2;
    delete pM3;

    return 0;
}