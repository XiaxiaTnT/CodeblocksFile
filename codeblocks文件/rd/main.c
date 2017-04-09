#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void p(int* a,int n){
    int i,j;
    int num=0;
    for(i=2;i<n;i++){
        int flag=0;
        int t=sqrt(i);
        for(j=2;j<=t;j++){
            if(i%j==0){flag=1;break;}
        }
        if(flag==0){
            a[num]=i;
            num++;
        }
    }
}
int main()
{  int a[50];
    memset(a,-1,sizeof(a));
    int n=rand()%50+1;
    p(a,n);
    int i;
    for(i=0;a[i]>-1;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
