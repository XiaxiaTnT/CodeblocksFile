#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define N 100
void getarry(double A[N][N],int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
}
void chline(double A[N][N],int i;int j;int n){
    for(int t=1;t<=n;t++){
        swap(A[i][t],A[j][t]);
    }
}
int main(){
int n;
}
