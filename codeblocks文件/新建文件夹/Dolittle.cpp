#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define ll 100
void dolittle(double A[][ll],int N){
    for(int i=2;i<=N;i++){
        A[i][1]=A[i][1]/A[1][1];
    }
    for(int k=2;k<=N;k++){
        for(int i=k;i<=N;i++){
            double sum1=0;
            for(int j=1;j<=k-1;j++){
                sum1+=A[k][j]*A[j][i];
            }
            A[k][i]=A[k][i]-sum1;
        }
        for(int i=k+1;i<=N;i++){
            double sum2=0;
            for(int j=1;j<=k-1;j++){
                sum2+=A[i][j]*A[j][k];
            }
            A[i][k]=(A[i][k]-sum2)/A[k][k];
        }
    }
}
void getA(double A[][ll],int N){
cout<<"ÇëÊäÈë¾ØÕóA"<<endl;
for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
        cin>>A[i][j];
    }
}
}
void show(double A[][ll],int N){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void showL(double A[][ll],int N){
    cout<<"LÎª£º"<<endl;
for(int i=1;i<=N;i++){
    for(int j=1;j<i;j++){
        cout<<A[i][j]<<" ";
    }
    cout<<1<<" ";
    for(int j=i+1;j<=N;j++){
        cout<<0<<" ";
    }
    cout<<endl;
}
}
void showU(double A[][ll],int N){
        cout<<"UÎª£º"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
                cout<<0<<" ";
            }
        for(int j=i;j<=N;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void getAS(double A[][ll],double B[ll],double x[ll],int N){
    double Y[ll];
    Y[1]=B[1];
    for(int k=2;k<=N;k++){
        double sum=0;
        for(int j=1;j<=k-1;j++){
            sum+=A[k][j]*Y[j];
        }
        Y[k]=B[k]-sum;
    }
    x[N]=Y[N]/A[N][N];
    for(int k=N-1;k>=1;k--){
        double sum=0;
        for(int j=k+1;j<=N;j++){
            sum+=A[k][j]*x[j];
        }
        x[k]=(Y[k]-sum)/A[k][k];
    }
}
void getB(double B[ll],int N){
    cout<<"ÇëÊäÈëb"<<endl;
for(int i=1;i<=N;i++){
    cin>>B[i];
}
}
void showAS(double x[ll],int N){
    cout<<"the answer is:"<<endl;
for(int i=1;i<=N;i++){
    cout<<"x"<<i<<"="<<x[i]<<" ";
}
}
void showb(double b[ll],int N){
cout<<"the arry b is:"<<endl;
for(int i=1;i<=N;i++){
    cout<<b[i]<<" ";
}
}
void redefine(double B[ll],double x[ll],int N){
double Max=fabs(x[1]);
for(int i=2;i<=N;i++){
    if(fabs(x[i])>Max){
        Max=fabs(x[i]);
}
}
for(int i=1;i<=N;i++){
    B[i]=x[i]/Max;
}
}
int main(){
double A[ll][ll];
double B[ll];
double x[ll];
cout<<"¾ØÕó½×Êý£º";
int N;
cin>>N;
getA(A,N);
dolittle(A,N);
showL(A,N);
showU(A,N);
getB(B,N);
for(int i=1;i<=10;i++){
    showb(B,N);cout<<endl;
    getAS(A,B,x,N);
    showAS(x,N);
    redefine(B,x,N);
    cout<<endl;
    cout<<endl;
}
return 0;
}
