#include <iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    double a[20]={0.594,0.928,0.515,0.055,0.507,0.351,0.262,0.797,0.788,0.442,
    0.097,0.798,0.227,0.127,0.474,0.825,0.007,0.182,0.929,0.852};
    double b[20];
    sort(a,a+20);
    /*for(int i=0;i<20;i++){
        cout<<a[i]<<" ";
    }
    for(int i=0;i<20;i++){
        b[i]=(i+1)/20;
    }*/
    for(int i=0;i<50;i++){
        cout<<i*(i+1)*(2*i+1)*1.0/180<<endl;
    }
    cout<<endl;
    return 0;
}
