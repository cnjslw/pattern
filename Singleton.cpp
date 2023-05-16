/*******************************************************
游戏设计V1：创建一个配置项，但是全局只能创建一个配置类对象
*******************************************************/

class GameConfig {
private:
    GameConfig() { }
    ~GameConfig() { }
    GameConfig(const GameConfig&) { }
    GameConfig& operator=(const GameConfig& tmpobj) { }

public:
    static GameConfig* getInstance()
    {
        if (m_instance == nullptr) {
            m_instance = new GameConfig();
        }
        return m_instance;
    }

private:
    static GameConfig* m_instance;
};

GameConfig* GameConfig::m_instance = nullptr;

int main()
{
    GameConfig* g_gc = GameConfig::getInstance();
    return 0;
}