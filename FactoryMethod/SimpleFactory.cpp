/*******************************************************
游戏设计V1：设计怪物，亡灵类怪物，元素类怪物，机械类怪物
*******************************************************/
/*******************************************************
游戏设计V2：如果怪物种类不断增加，每次创建怪物需要知道怪物的名字还要知道怪物的类的构造函数，创建工厂类，屏蔽掉这些这些细节
*******************************************************/
/*******************************************************
游戏设计V3：静态工厂类
*******************************************************/
#include <iostream>
#include <string>
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

class MonsterFactory {
public:
    static Monster* createMonster(std::string strmontype)
    {
        Monster* ptrnobj = nullptr;
        if (strmontype == "uud") {
            ptrnobj = new M_Undead(300, 50, 80);
        } else if (strmontype == "elm") {
            ptrnobj = new M_Element(200, 40, 90);
        } else if (strmontype == "mec") {
            ptrnobj = new M_Mechanic(500, 10, 20);
        }
        return ptrnobj;
    }

public:
    MonsterFactory(/* args */) { }
    ~MonsterFactory() { }
};

int main()
{
    // V1
    //  M_Undead* pM1 = new M_Undead(300, 50, 80);
    //  M_Element* pM2 = new M_Element(200, 40, 90);
    //  M_Mechanic* pM3 = new M_Mechanic(500, 10, 20);

    // delete pM1;
    // delete pM2;
    // delete pM3;

    // v2
    // MonsterFactory facobj;
    // Monster* pM1 = facobj.createMonster("uud");
    // Monster* pM2 = facobj.createMonster("elm");
    // Monster* pM3 = facobj.createMonster("mec");
    // delete pM1;
    // delete pM2;
    // delete pM3;

    // V3
    Monster* pM1 = MonsterFactory::createMonster("uud");
    Monster* pM2 = MonsterFactory::createMonster("elm");
    Monster* pM3 = MonsterFactory::createMonster("mec");
    delete pM1;
    delete pM2;
    delete pM3;

    return 0;
}