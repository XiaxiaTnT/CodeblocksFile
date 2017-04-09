#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int a,int b){
int t;
t=a;
a=b;
b=t;
}
int Random(int a,int b){
    return rand()%(b-a)+a;
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
    scanf("%d",&n);
    int i;
    for(i=1;i<n;i++){
        scanf(" %d",&a[i]);
    }
    RandomizedQuickSort(a,1,n);
    for(i=1;i<n;i++){
    printf(" %d",a[i]);
}
return 0;
}
