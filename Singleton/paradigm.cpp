class Single()
{
    public:
        static Single& GetInstance(){
            static Single signal;//内部调用构造函数
            return signal;
        }
    
    private:
        Single(){}
        ~Single(){}
        Single(const Single& signal){}
        const Single &operator=(const Single &signal){}
};
