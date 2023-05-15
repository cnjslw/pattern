#include <iostream>
template <typename T>
class myIter {
private:
    /* data */
public:
    myIter(/* args */) { }
    virtual ~myIter() { }
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool isDone() = 0;
    virtual T& CurrentItem() = 0;
};

template <typename T>
class myCotainer {
private:
    /* data */
public:
    myCotainer(/* args */) { }
    virtual ~myCotainer() { }
    virtual T& getItem(int index) = 0;
    virtual int getSize() = 0;
    virtual myIter<T>* CreateIterator() = 0;
};

template <typename T>
class myVectorIter : public myIter<T> {
private:
    myCotainer<T>* myvector;
    int m_current;

public:
    myVectorIter(myCotainer<T>* tmpc)
        : myvector(tmpc)
    {
        m_current = 0;
    }
    ~myVectorIter() override { }

public:
    virtual void First()
    {
        m_current = 0;
    }
    virtual void Next() { m_current++; }
    virtual bool isDone()
    {
        if (m_current >= myvector->getSize()) {
            return true;
        }
        return false;
    }
    virtual T& CurrentItem()
    {
        return myvector->getItem(m_current);
    }
};

template <typename T>
class myVector : public myCotainer<T> {
public:
    myVector()
    {
        for (int i = 0; i < 10; i++) {
            m_elem[i] = i;
        }
    }
    virtual ~myVector() { }

private:
    T m_elem[10];

public:
    virtual myIter<T>* CreateIterator()
    {
        return new myVectorIter<T>(this);
    }

    virtual T& getItem(int index)
    {
        return m_elem[index];
    }

    virtual int getSize()
    {
        return 10;
    }
};

int main()
{
    // myCotainer<int>* pcontainer = new myVector<int>();
    // myIter<int>* iter = pcontainer->CreateIterator();
    // for (iter->First(); !iter->isDone(); iter->Next()) {
    //     std::cout << iter->CurrentItem() << " ";
    // }
    // std::cout << std::endl;
    // delete iter;
    // delete pcontainer;
    myCotainer<int>* pcontainer = new myVector<int>();
    myVectorIter<int> iter(pcontainer);
    for (iter.First(); !iter.isDone(); iter.Next()) {
        std::cout << iter.CurrentItem() << " ";
    }
    delete pcontainer;
    return 0;
}