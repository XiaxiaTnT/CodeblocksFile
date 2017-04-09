#include <iostream>
#include<stdio.h>
#include<string.h>
#define num 100005
using namespace std;
int main()
{
    int a[num];
int n;
cin>>n;
memset(a,0,sizeof(a));
while(n--){
    int t;
    scanf("%d",&t);

    int ll=0;
    if(t==1){scanf("%d",&ll);
    }
    else{
    while(t--){
        scanf("%d",&ll);
        a[ll]=1;
    }
    }
}
int nn;
cin>>nn;
int mm;
int flag=0;
int f=0;
while(nn--){
    scanf("%d",&mm);
    if(a[mm]==0){
            if(f==0){
                printf("%05d",mm);f=1;
            }
            else{
            printf(" %05d",mm);
            }
            a[mm]=1;flag=1;
    }
}
if(flag==0){cout<<"No one is handsome"<<endl;}
return 0;
}
