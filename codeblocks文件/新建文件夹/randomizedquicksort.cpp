#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
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
int RandomizedPartition(int a[],int p,int r){
    int i=Random(p,r);
    swap(a[i],a[p]);
    return Partition(a,p,r);
}
void RandomizedQuickSort(int a[],int p,int r){
    if(p<r){
        int q=RandomizedPartition(a,p,r);
        RandomizedQuickSort(a,p,q);
        RandomizedQuickSort(a,q+1,r);
        }
}
int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    RandomizedQuickSort(a,1,n);
    for(int i=1;i<n;i++){
    cout<<" "<<a[i];
}
return 0;
}
