#include <iostream>

using namespace std;
class Base{
public:Base(){};
public:
    void fun(int a,int b)
    {
        cout<<"Base fun "<<a<<" "<<b<<endl;
    }
    virtual void func(int a,int b)
    {
        cout<<"Base func "<<a<<" "<<b<<endl;
    }

};
class Derived:public Base
{
    public:Derived(){};
    public:
        void fun(int a,int b)
        {
            cout<<"Derived fun "<<a<<" "<<b<<endl;
        }
        void func(int a,int b)
        {
            cout<<"Derived func "<<a<<" "<<b<<endl;
        }
        void fun(int a,int b,int c)
        {
            cout<<"Derived fun "<<a<<" "<<b<<" "<<c<<endl;
        }
};
int main()
{
    Base *base=new Derived();
    base->fun(1,2);
    base->func(1,2);
    //base->fun(1,2,3);
    return 0;
}
