#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
using namespace std;
typedef long long LL;
const int INF=0x7fffffff;
const int MAXN=1000;
const double wucha=0.0001;
const int MAX_count=200;

double A[MAXN][MAXN];
double b[MAXN];
double curx[MAXN];
double lastx[MAXN];
int N,Count;
double W;

void init(){
    printf("输入未知数个数：");
    cin>>N;
    printf("输入方程组矩阵A：\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>A[i][j];
        }
    }
    printf("输入b向量：\n");
    for(int i=1;i<=N;i++){
        cin>>b[i];
    }
    cout<<endl;
}

void initx(){
//    memset(curx,-1,sizeof(curx));
    cout<<"请对x赋初值："<<endl;
    for(int i=1;i<=N;i++){
        cin>>curx[i];
    }
}

bool judge(){
    double sum=0;
    for(int i=1;i<=N;i++){
        sum+=(curx[i]-lastx[i])*(curx[i]-lastx[i]);
    }
    sum=sqrt(sum);
    if(sum<=wucha)return 1;
    else return 0;
}

void shuchux(){
    cout<<"迭代次数为："<<Count<<endl;
    cout<<"近似解为：";
    for(int i=1;i<=N;i++){
        cout<<curx[i]<<" ";
    }
    cout<<endl<<endl;
}

void Jacobi(){//x初值都设置为0
    cout<<"雅可比迭代法："<<endl;
    initx();
    int flag=0;
    double sum;
    for(int k=1;k<MAX_count;k++){
        for(int i=1;i<=N;i++){
            lastx[i]=curx[i];
        }

        for(int i=1;i<=N;i++){
            sum=0;
            for(int j=1;j<=N;j++){
                if(i==j)continue;
                sum+=A[i][j]*lastx[j];
            }
            curx[i]=(b[i]-sum)/A[i][i];
        }
        if(judge()){
            flag=1;
            Count=k;
            shuchux();
            break;
        }
    }
    if(flag==0)cout<<"error！"<<endl<<endl;
}

void gaisi_saideer(){
    cout<<"高斯—赛德尔迭代法："<<endl;
    initx();
    int flag=0;
    double sum;
    double t;
    for(int k=1;k<MAX_count;k++){
        double e=0;
        for(int i=1;i<=N;i++){
            t=curx[i];
            sum=0;
            for(int j=1;j<=N;j++){
                if(i==j)continue;
                sum+=A[i][j]*curx[j];
            }
            curx[i]=(b[i]-sum)/A[i][i];
            if(fabs(curx[i]-t)<=e){}
            else {
                e=fabs(curx[i]-t);
            }
        }
        if(e<wucha){
            flag=1;
            Count=k;
            shuchux();
            break;
        }
    }
    if(flag==0)cout<<"error！"<<endl<<endl;
}

void SOR(){
    cout<<"逐次超松弛迭代法（SOR）："<<endl;
    initx();
    cout<<"输入松弛因子W:"<<endl;
    cin>>W;
    int flag=0;
    double sum;
    double t;
    for(int k=1;k<MAX_count;k++){
        double e=0;
        for(int i=1;i<=N;i++){
            t=curx[i];
            sum=0;
            for(int j=1;j<=N;j++){
                if(i==j)continue;
                sum+=A[i][j]*curx[j];
            }
            curx[i]=W*(b[i]-sum)/A[i][i];
            if(fabs(curx[i]-t)<=e){}
            else {
                e=fabs(curx[i]-t);
            }
        }
        if(e<wucha){
//            for(int i=1;i<=N;i++){
//                curx[i]/=W;
//            }
            flag=1;
            Count=k;
            shuchux();
            break;
        }
    }
    if(flag==0)cout<<"error！"<<endl<<endl;
}

int main(){
    while(1){
        init();
        Jacobi();
        gaisi_saideer();
        SOR();
        SOR();
        SOR();
    }
    return 0;
}
