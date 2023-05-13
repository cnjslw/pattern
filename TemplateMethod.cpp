/*
游戏设计V1：定义一个战士，有战斗力，魔法值
*/
#include <iostream>

class Warrior {
private:
    int m_life;
    int m_magic;
    int m_attack;

public:
    Warrior(int life, int magic, int attack) { }
    ~Warrior() { }

public:
    void JN_Burn()
    {
        std::cout << "让所有的敌人失去500生命值" << std::endl;
        std::cout << "主角自身失去300生命值" << std::endl;
        m_life -= 300;
        std::cout << "播放燃烧特效" << std::endl;
    }
};

int main()
{
    Warrior mroleobj(1000, 0, 200);
    mroleobj.JN_Burn();
    return 0;
}