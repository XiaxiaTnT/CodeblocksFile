#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    double m;int a[32],b[10];
    while(1){
    int ia=0;int t;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>m;
    int mf=(int)m;
    //cout<<m<<endl;
    m=m-mf;
    //cout<<m<<endl;
    while(mf!=0){
        t=mf;
        a[ia]=t%2;
        mf=mf/2;
        ia++;
    }
    int ml;
    for(int ib=0;ib<8;ib++){
        m=m*2;
        ml=(int)m;
        b[ib]=ml;
        m=m-ml;
    }
    if(ia==0){cout<<"0 ";}
    else{for(int j=ia-1;j>=0;j--){
        cout<<a[j]<<" ";
    }}
    cout<<". ";
    for(int j=0;j<8;j++){
        cout<<b[j]<<" ";
    }
    cout<<endl;
    }
    return 0;
}
