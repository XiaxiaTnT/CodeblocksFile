#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int Partition(int a[],int p,int r);
void quicksort(int a[],int p,int r){
     if(p<r){
        int q=Partition(a,p,r);
        quicksort(a,p,q);
        quicksort(a,q+1,r);
     }
}
int Partition(int a[],int p,int r){
    int i=p;int j=r+1;
    int x=a[p];
    while(1){
        while(a[++i]<x&&i<r);
        while(a[--j]>x);
        if(i>=j)break;
        swap(a[i],a[j]);
    }
    swap(a[p],a[j]);
    return j;
}
int main(){
int a[100];
int n;
cin>>n;
for(int i=1;i<n;i++){
    cin>>a[i];
}
quicksort(a,1,n);
for(int i=1;i<n;i++){
    cout<<" "<<a[i];
}
return 0;

}
