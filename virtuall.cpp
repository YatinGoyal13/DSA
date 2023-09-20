#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class abc;
class animal
{
private:
    int y;

public:
    animal(int n)
    {
        y = n;
    }
    void display()
    {
        cout << "jigsu bevkoof" << endl;
    }
    friend int summ(animal xx,abc yy);
};

class abc
{
private:
    int x;

public:
    abc(int d)
    {
        x = d;
    }
    void display()
    {
        cout << "jigsu nalayak" << endl;
    }
    friend int summ(animal xx,abc yy);
};

int summ(animal xx,abc yy)
{
    return (xx.y+yy.x);
}


int main()
{
    animal a(2);
    abc aa(3);
    cout<<summ(a,aa);
   
}
