#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define LL 10000
int Partition(int a[],int p,int r,int x);
int Select(int a[],int p,int r,int k){
    if(r-p<75){
            sort(a+p,a+r+1);
            return a[p+k-1];
}
for(int i=0;i<=(r-p-4)/5;i++){
    sort(a+(p+5*i),a+(p+5*i+5));
    swap(a[p+i],a[p+5*i+2]);
}
int x=Select(a,p,p+(r-p-4)/5,(r-p-4)/10);
int i=Partition(a,p,r,x),j=i-p+1;
if(k<=j)return Select(a,p,i,k);
else return Select(a,i+1,r,k-j);
}
int Partition(int a[],int p,int r,int x){
    int i=p-1,j=r+1;
    while(1){
        while(a[++i]<x&&i<r);
        while(a[--j]>x);
        if(i>=j)break;
        swap(a[i],a[j]);
    }
    return j;
}
void show(int A[],int N){
    for(int j=1;j<N;j++){
    cout<<" "<<A[j];
    if(j%20==0)cout<<endl;
}
}
int main(){
int A[LL];
int N;
cout<<"请输入数据规模"<<endl;
cin>>N;
for(int i=1;i<=N;i++){
    A[i]=rand()%1000+1;
}
show(A,N);cout<<endl;
int k;
cout<<"输入要查找的数的位置"<<endl;
cin>>k;
int t=Select(A,1,N,k);
printf("第%d个数为%d",k,t);cout<<endl;
cout<<"验证："<<endl;
sort(A,A+N+1);
show(A,N);
return 0;
}
