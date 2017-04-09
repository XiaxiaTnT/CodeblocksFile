#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define ll 100
void getA(int n,double A[][ll]){
    cout<<"输入A:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A[i][j];
        }
    }
}
void getb(int n,double b[ll]){
    cout<<"输入b:"<<endl;
for(int i=1;i<=n;i++){
    cin>>b[i];
}
}
void getx(int n,double x[ll]){
    cout<<"输入x:"<<endl;
for(int i=1;i<=n;i++){
    cin>>x[i];
}
}
void jacobi(int n,double A[][ll],double b[ll],double X[ll],double t,int N){
int k=1;double y[n+1];double e;
double x[ll];
for(int i=1;i<=n;i++){
    x[i]=X[i];
}
cout<<"雅可比迭代："<<endl;
while(N){
    for(int i=1;i<=n;i++){
        double sum=0;
        for(int j=1;j<=n;j++){
                if(i==j)continue;
            sum+=A[i][j]*x[j];
        }
        y[i]=(b[i]-sum)/A[i][i];
    }
    double  s=0;
    for(int i=1;i<=n;i++){
        s+=(y[i]-x[i])*(y[i]-x[i]);
    }
    e=sqrt(s);
    if(e<t){
        cout<<k<<endl;
        for(int i=1;i<=n;i++){
            cout<<"x"<<i<<"="<<y[i]<<" ";
            }
            cout<<endl;
        return ;
    }
    else{
        for(int i=1;i<=n;i++){
            x[i]=y[i];
        }
    }
    if(k>=N){
        cout<<"false"<<endl;
        return;
    }
    k++;
    }
}
void Gauss_seidel(int n,double A[][ll],double b[ll],double X[ll],double t,int N){
    int k=1;double e;double y[ll]={0};
    double x[ll];
    for(int i=1;i<=n;i++){
    x[i]=X[i];
}
    cout<<"高斯——赛德尔迭代："<<endl;
    while(1){
        for(int i=1;i<=n;i++){
            double sum1,sum2;
            sum1=sum2=0;
            for(int j=1;j<=i-1;j++){
                sum1+=A[i][j]*y[j];
            }
            for(int j=i+1;j<=n;j++){
                sum2+=A[i][j]*x[j];
            }
            y[i]=(b[i]-sum1-sum2)/A[i][i];
        }
        double s=0;
        for(int i=1;i<=n;i++){
            s+=(y[i]-x[i])*(y[i]-x[i]);
        }
        e=sqrt(s);
        if(e<t){
            cout<<"k="<<k<<endl;
            for(int i=1;i<=n;i++){
                cout<<"x"<<i<<"="<<y[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            for(int i=1;i<=n;i++){
                x[i]=y[i];
            }
        }
        if(k>=N){
            cout<<"false"<<endl;
            return;
        }
        k++;
    }
}
void SOR(int n,double A[][ll],double b[ll],double X[ll],double t,int N){
    int k=1;double e;double y[ll]={0};
    double x[ll];
    for(int i=1;i<=n;i++){
    x[i]=X[i];
}
    double w;
    cout<<"逐次超松弛迭代法："<<endl;
    cout<<"松弛因子：";
    cin>>w;
    while(1){
        for(int i=1;i<=n;i++){
            double sum1,sum2;
            sum1=sum2=0;
            for(int j=1;j<=i-1;j++){
                sum1+=A[i][j]*y[j];
            }
            for(int j=i;j<=n;j++){
                sum2+=A[i][j]*x[j];
            }
            y[i]=(b[i]-sum1-sum2)*w/A[i][i]+x[i];
        }
        double s=0;
        for(int i=1;i<=n;i++){
            s+=(y[i]-x[i])*(y[i]-x[i]);
        }
        e=sqrt(s);
        if(e<t){
            cout<<"k="<<k<<endl;
            for(int i=1;i<=n;i++){
                cout<<"x"<<i<<"="<<y[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            for(int i=1;i<=n;i++){
                x[i]=y[i];
            }
        }
        if(k>=N){
            cout<<"false"<<endl;
            return;
        }
        k++;
    }
}
int main(){
    double a[ll][ll],b[ll],X[ll],t;
    int n,N;
    cout<<"矩阵阶数：";
    cin>>n;
    cout<<"最大迭代次数：";
    cin>>N;
    cout<<"精度要求：";
    cin>>t;
    getA(n,a);
    getb(n,b);
    getx(n,X);
    jacobi(n,a,b,X,t,N);
    Gauss_seidel(n,a,b,X,t,N);
    int p=3;
    while(p--){
        SOR(n,a,b,X,t,N);
        cout<<endl;
    }
    return 0;
}
