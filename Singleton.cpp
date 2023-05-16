/*******************************************************
游戏设计V1：创建一个配置项，但是全局只能创建一个配置类对象（懒汉模式）
*******************************************************/

// class GameConfig {
// private:
//     GameConfig() { }
//     ~GameConfig() { }
//     GameConfig(const GameConfig&) { }
//     GameConfig& operator=(const GameConfig& tmpobj) { }

// public:
//     static GameConfig* getInstance()
//     {
//         if (m_instance == nullptr) {
//             m_instance = new GameConfig();
//         }
//         return m_instance;
//     }

// private:
//     static GameConfig* m_instance;
// };

// GameConfig* GameConfig::m_instance = nullptr;

// int main()
// {
//     GameConfig* g_gc = GameConfig::getInstance();
//     return 0;
// }

/*******************************************************
游戏设计V2：双重加锁保证在多线程中的安全
*******************************************************/

// 这段代码实现了单例模式，通过静态函数 getInstance() 获取唯一实例，并且限制了外部创建、删除和复制对象的操作。
// 具体地，使用了原子指针来保证线程安全，同时使用了内存屏障来确保顺序性和可见性。此外，还使用了互斥锁来保护实例的创建，防止多个线程同时创建新的实例。

// #include <atomic>
// #include <mutex>
// class GameConfig {
// private:
//     GameConfig() { } // 私有构造函数，限制外部创建对象
//     ~GameConfig() { } // 私有析构函数，限制外部删除对象
//     GameConfig(const GameConfig& tmpobj) { } // 私有拷贝构造函数，防止对象被复制
//     GameConfig operator=(const GameConfig& tmpobj) { } // 私有赋值运算符，防止对象被赋值

// public:
//     static GameConfig* getInstance() // 获取唯一实例的静态函数
//     {
//         GameConfig* tmp = m_instance.load(std::memory_order_relaxed); // relaxed内存模型下获取实例指针
//         std::atomic_thread_fence(std::memory_order_acquire); // acquire内存模型下的内存屏障，确保后续操作不会越过此处
//         if (tmp == nullptr) { // 如果实例指针为空，则需要创建新的实例
//             tmp = new GameConfig(); // 先尝试创建一个实例
//             std::atomic_thread_fence(std::memory_order_release); // release内存模型下的内存屏障，确保前面的操作不会越过此处
//             if (tmp == nullptr) { // 如果创建失败，则再次尝试创建一个实例
//                 tmp = new GameConfig();
//                 std::atomic_thread_fence(std::memory_order_release);
//                 m_instance.store(tmp, std::memory_order_relaxed); // relaxed内存模型下保存实例指针
//             }
//         }
//         return tmp; // 返回实例指针
//     }

// private:
//     static std::atomic<GameConfig*> m_instance; // 唯一实例的原子指针
//     static std::mutex m_mutex; // 保护实例创建的互斥锁
// };
// std::atomic<GameConfig*> GameConfig::m_instance; // 静态成员变量需要在类外初始化
// std::mutex GameConfig::m_mutex; // 静态成员变量需要在类外初始化

// int main()
// {
//     GameConfig* g_gc = GameConfig::getInstance();
//     return 0;
// }

/*******************************************************
游戏设计V3：饿汉模式与懒汉模式（V1）保证在多线程中的安全
*******************************************************/
// class GameConfig {
// private:
//     GameConfig() { }
//     ~GameConfig() { }
//     GameConfig(const GameConfig&) { }
//     GameConfig& operator=(const GameConfig& tmpobj) { }

// public:
//     static GameConfig* getInstance()
//     {
//         return m_instance;
//     }

// private:
//     static GameConfig* m_instance;
// };

// GameConfig* GameConfig::m_instance = new GameConfig();

// int main()
// {
//     GameConfig* g_gc = GameConfig::getInstance();
//     return 0;
// }

/*******************************************************
游戏设计V4：类对象的内存回收问题
*******************************************************/
class GameConfig {
private:
    GameConfig() { }
    ~GameConfig() { }
    GameConfig(const GameConfig&) { }
    GameConfig& operator=(const GameConfig& tmpobj) { }

public:
    // 饿汉模式下的自动析构
    static GameConfig* getInstance()
    {
        return m_instance;
    }

    /*手动析构*/
    // static void freeInstance()
    // {
    //     if (m_instance != nullptr) {
    //         delete m_instance;
    //         GameConfig::m_instance = nullptr;
    //     }
    // }
    // 懒汉模式下的自动析构
    // static GameConfig* getInstance()
    // {
    //     if (m_instance == nullptr) {
    //         m_instance = new GameConfig();
    //         static Garbo agrboobj;
    //     }
    //     return m_instance;
    // }

private:
    class Garbo {
    public:
        ~Garbo()
        {
            if (GameConfig::m_instance != nullptr) {
                delete GameConfig::m_instance;
                GameConfig::m_instance = nullptr;
            }
        }
    };

    static GameConfig* m_instance;
    static Garbo agrboobj;
};

GameConfig* GameConfig::m_instance = new GameConfig();
GameConfig::Garbo GameConfig::agrboobj;

int main()
{
    GameConfig* g_gc = GameConfig::getInstance();
    // 手动析构
    // GameConfig::freeInstance();

    // 懒汉模式下的自动析构
    g_gc = nullptr;

    return 0;
}