#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int decimalNumber(string str)
{
    string result;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u'||
            str[i]=='A' ||str[i]=='E' ||str[i]=='I' ||str[i]=='O' ||str[i]=='U'){
            result+= "0";
        }
        else{
             result+= "1";
        }
        
    }
    return stoi(result, 0, 2);
}
int main() {
    string s;
    cin>>s;
    cout<<decimalNumber(s)<<endl;
    }