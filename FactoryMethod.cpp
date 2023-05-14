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
// 简单工厂模型核心代码
//  class MonsterFactory {
//  public:
//      static Monster* createMonster(std::string strmontype)
//      {
//          Monster* ptrnobj = nullptr;
//          if (strmontype == "uud") {
//              ptrnobj = new M_Undead(300, 50, 80);
//          } else if (strmontype == "elm") {
//              ptrnobj = new M_Element(200, 40, 90);
//          } else if (strmontype == "mec") {
//              ptrnobj = new M_Mechanic(500, 10, 20);
//          }
//          return ptrnobj;
//      }

// public:
//     MonsterFactory(/* args */) { }
//     ~MonsterFactory() { }
// };

class M_ParFactory {
public:
    virtual Monster* createMonster() = 0;
    virtual ~M_ParFactory() { }
};

class M_UndeadFactory : public M_ParFactory {
private:
    /* data */
public:
    virtual Monster* createMonster()
    {
        return new M_Undead(300, 50, 80);
    }
};

class M_ElementFactory : public M_ParFactory {
private:
    /* data */
public:
    virtual Monster* createMonster()
    {
        return new M_Element(200, 40, 90);
    }
};

class M_MechanicFactory : public M_ParFactory {
private:
    /* data */
public:
    virtual Monster* createMonster()
    {
        return new M_Mechanic(500, 10, 20);
    }
};

Monster* Gbl_CreateMonster(M_ParFactory* factory)
{
    return factory->createMonster();
}

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
    // Monster* pM1 = MonsterFactory::createMonster("uud");
    // Monster* pM2 = MonsterFactory::createMonster("elm");
    // Monster* pM3 = MonsterFactory::createMonster("mec");
    // delete pM1;
    // delete pM2;
    // delete pM3;

    M_ParFactory* p_ud_fy = new M_UndeadFactory();
    Monster* pM1 = Gbl_CreateMonster(p_ud_fy);

    M_ParFactory* p_elm_fy = new M_ElementFactory();
    Monster* pM2 = Gbl_CreateMonster(p_elm_fy);

    M_ParFactory* p_mec_fy = new M_MechanicFactory();
    Monster* pM3 = Gbl_CreateMonster(p_elm_fy);

    return 0;
}