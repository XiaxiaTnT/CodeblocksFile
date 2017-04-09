#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define N 100
void getarry(double A[N][N],int n){
    cout<<"getA"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
}
void getb(double b[N],int n){
    cout<<"getb"<<endl;
for(int i=1;i<=n;i++){
    cin>>b[i];
}
}
void getab(double A[][N],double b[],int n){
    int t=n+1;
for(int i=1;i<=n;i++)
    {
        A[i][t]=b[i];
    }
}
void show(double A[][N],int n){
    cout<<"A:"<<endl;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n+1;j++){
        cout<<A[i][j]<<" ";
    }
    cout<<endl;
}
}
void chline(double A[N][N],int i,int j,int n){
    for(int t=1;t<=n+1;t++){
        swap(A[i][t],A[j][t]);
    }
}
int maxnum(double A[N][N],int n,int t){
    double M=fabs(A[t][t]);
    int i=t;int s=t;
    for(t+1;t<=n;t++){
        if(fabs(A[t][i])>=M){M=fabs(A[t][i]);s=t;}
    }
    return s;
}
void xiaoyuan(double A[N][N],int t,int n){
for(int i=t+1;i<=n;i++){
    for(int j=t+1;j<=n+1;j++){
        A[i][j]=-A[i][t]*A[t][j]/A[t][t]+A[i][j];
    }
    A[i][t]=0;
}

}
int main(){
int n;double A[N][N];double b[N];
double ad;
cout<<"get n"<<endl;cin>>n;
cout<<"get *"<<endl;cin>>ad;
getarry(A,n);
getb(b,n);
getab(A,b,n);
for(int k=1;k<=n;k++){
    int s=maxnum(A,n,k);
    if(fabs(A[s][k])<ad){
        cout<<"det A=0"<<endl;
        return 0;
    }
    else if(s!=k){
        chline(A,s,k,n);
    }
    xiaoyuan(A,k,n);
}
if(fabs(A[n][n])<ad){
    cout<<"det A=0"<<endl;
    return 0;
    }
else{
    b[n]=A[n][n+1]/A[n][n];
    for(int i=n-1;i>0;i--){
        double sum=0;
        for(int j=n;j>i;j--){
            sum+=A[i][j]*b[j];
        }
        b[i]=(A[i][n+1]-sum)/A[i][i];
    }
}
for(int q=1;q<=n;q++)
    cout<<b[q]<<" ";
}
