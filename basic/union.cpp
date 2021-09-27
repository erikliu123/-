#include <iostream>

using namespace std;

class Token
{
public:
    //因为union含有一个string成员，所以Token必须定义拷贝控制成员
    Token() : tok(INT), ival(0) {}
    Token(const Token &t) : tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token &);
    ~Token()
    {

        if (tok == STR)
            sval.~string();
    }
    //下面的赋值运算符负责设置union的不同成员
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    Token &operator=(const std::string &);

private:
    //判别式
    enum
    {
        INT,
        CHAR,
        DBL,
        STR
    } tok;
    //匿名union
    union //test
    {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };
    //检查判别式，然后酌情拷贝union成员
    void copyUnion(const Token &);
};

union s//test
{
    char cval;
    int ival;
    double dval;
    std::string sval;
};
// static string s;
static union{
            char cval;
            int ival;
            double dval;
           // std::string sval;
};

int main()
{
    cout<<sizeof(s)<<endl;
    return 0;
}