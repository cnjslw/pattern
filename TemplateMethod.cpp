/*******************************************************
游戏设计V1：定义一个战士，有战斗力，魔法值
*******************************************************/
// #include <iostream>

// class Warrior {
// private:
//     int m_life;
//     int m_magic;
//     int m_attack;

// public:
//     Warrior(int life, int magic, int attack) { }
//     ~Warrior() { }

// public:
//     void JN_Burn()
//     {
//         std::cout << "让所有的敌人失去500生命值" << std::endl;
//         std::cout << "主角自身失去300生命值" << std::endl;
//         m_life -= 300;
//         std::cout << "播放燃烧特效" << std::endl;
//     }
// };

// int main()
// {
//     Warrior mroleobj(1000, 0, 200);
//     mroleobj.JN_Burn();
//     return 0;
// }

/******************************************************
游戏设计V2：增加一个角色-法师，有战斗力，魔法值，但是属性与展示不同
*******************************************************/

// 添加战斗者父类
#include <iostream>
class Fighter {
protected:
    int m_life;
    int m_magic;
    int m_attack;

public:
    Fighter(int life, int magic, int attack)
        : m_life(life)
        , m_magic(magic)
        , m_attack(attack)
    {
    }
    ~Fighter() { }

public:
    void JN_Burn()
    {
        effect_enemy();
        effect_self();
        play_effect();
    }

private:
    virtual void effect_enemy() {};
    virtual void effect_self() {};
    void play_effect()
    {
        std::cout << "播放燃烧特效" << std::endl;
    }
};

class F_Warrior : public Fighter {
public:
    F_Warrior(int life, int magic, int attack)
        : Fighter(life, magic, attack)
    {
    }
    ~F_Warrior() { }

public:
    virtual void effect_enemy()
    {
        std::cout << "让所有的敌人失去500生命值" << std::endl;
    }
    virtual void effect_self()
    {
        std::cout << "主角自身失去300生命值" << std::endl;
        m_life -= 300;
    }
};

class F_Mage : public Fighter {
public:
    F_Mage(int life, int magic, int attack)
        : Fighter(life, magic, attack)
    {
    }
    ~F_Mage() { }

public:
    virtual void effect_enemy()
    {
        std::cout << "让所有的敌人失去650生命值" << std::endl;
    }
    virtual void effect_self()
    {
        std::cout << "主角自身失去100点魔法值" << std::endl;
        m_magic -= 100;
    }
};

int main()
{
    Fighter* prole_war = new F_Warrior(1000, 0, 200);
    prole_war->JN_Burn();
    std::cout << "******************************************" << std::endl;
    Fighter* prole_mag = new F_Mage(800, 200, 300);
    prole_mag->JN_Burn();
    delete prole_mag;
    delete prole_war;
    return 0;
}