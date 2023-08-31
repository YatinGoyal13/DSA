#include<iostream>
using namespace std;
int func()
{
    static int num=16;
    return num--;
}
int main()
{
    struct bits
    {
    int  i:40;

    }bit;
    cout<<sizeof(bit);
}