#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> stu;
    int mm=0;
    int mmx=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        stu.push_back(d);
        if(d>mmx)
        {
            mm=i;
            mmx=d;}


    }
    // sort(stu.begin(),stu.end(),greater<int>());
    int j=0;
    int count=0;
    while(stu[mm]>0)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=j)
            {
                stu[i]--;
            }
        }
        j++;
        count++;
        if (j==n-1)
        {
            j=0;
        }
    }
    cout<<count<<endl;
}