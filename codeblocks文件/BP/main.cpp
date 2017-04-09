#include <iostream>
#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
using namespace std;
#define innum 1
#define hidenum 10
#define outnum 1
#define trainnum 7
#define rate 0.9
double in[trainnum][innum]={
    {1.0},{1.1},{1.2},{1.3},{1.4},{1.5},{1.570796}
    };
double out[trainnum][outnum]={
    {0.982943/2.0},{1.082416/2.0},{1.164079/2.0},{1.227117/2.0},{1.270900/2.0},{1.294990/2.0},{1.3/2.0}
    };
double m[innum]={1.57};
//double in[trainnum][innum];//测试输入
//double out[trainnum][outnum];//测试输出
double w1[innum][hidenum];//隐含层权值
double w2[hidenum][outnum];//输出层权值
double fa1[hidenum];//隐含层阀值
double fa2[outnum];//输出层阀值
double yy[hidenum];//隐含层均方差
double ss[outnum];//输出层均方差
double y[outnum];//输出
double x[innum];//输入
double x1[hidenum];//隐含层值
double x2[outnum];//输出层值
double o1[hidenum];//隐含层激活值
double o2[outnum];//输出层激活值
double error=1.0;
double e=0.0;
double t1,t2;
void init(){
    for(int i=0;i<innum;i++){
        for(int j=0;j<hidenum;j++){
            w1[i][j]=(2.0*(double)rand()/RAND_MAX)-1;
        }
    }
    for(int i=0;i<hidenum;i++){
        for(int j=0;j<outnum;j++){
            w2[i][j]=(2.0*(double)rand()/RAND_MAX)-1;
        }
    }
    for(int i=0;i<hidenum;i++){
        fa1[i]=(2.0*(double)rand()/RAND_MAX)-1;
        //fa1[i]=(rand()%9)/10;
    }
    for(int i=0;i<outnum;i++){
        fa2[i]=(2.0*(double)rand()/RAND_MAX)-1;
        //fa2[i]=(rand()%9)/10;
    }
}

int ct=0;
void train(){
    for(int tn=0;tn<trainnum;tn++){
            ct++;

        for(int i=0;i<innum;i++){
            x[i]=in[tn][i];
        }
        for(int i=0;i<outnum;i++){
            y[i]=out[tn][i];
        }
        for(int j=0;j<hidenum;j++){
             o1[j]=0.0;
             //t1=0.0;
             for(int i=0;i<innum;i++){
                o1[j]=o1[j]+w1[i][j]*x[i];
             }

             //x1[j]=2.0/(1+exp(-o1[j]+fa1[j]))-1.0;
             x1[j]=1/(1+exp(-o1[j]-fa1[j]));

             //cout<<x1[j]<<" ";
        }
        //cout<<endl;
        for(int j=0;j<outnum;j++){
            o2[j]=0.0;
            //t2=0.0;
            for(int i=0;i<hidenum;i++){
                o2[j]=o2[j]+w2[i][j]*x1[i];
            }

            //x2[j]=2.0/(1+exp(-o2[j]+fa2[j]))-1.0;
            x2[j]=1/(1+exp(-o2[j]-fa2[j]));

            //cout<<x2[j]<<" ";
        }
        //cout<<endl;
        //update w2
        for(int i=0;i<outnum;i++){
            ss[i]=(y[i]-x2[i])*x2[i]*(1-x2[i]);
            for(int j=0;j<hidenum;j++){
                w2[j][i]+=rate*ss[i]*x1[i];
            }
        }
        //update w1
        for(int i=0;i<hidenum;i++){
            yy[i]=0.0;
            for(int j=0;j<outnum;j++){
                yy[i]=yy[i]+ss[j]*w2[i][j];
            }
            yy[i]=yy[i]*x1[i]*(1-x1[i]);
            for(int k=0;k<innum;k++){
                w1[k][i]+=rate*yy[i]*x[k];
            }
        }
        for(int i=0;i<outnum;i++){
            e+=fabs(y[i]-x2[i])*fabs(y[i]-x2[i]);
        }
        error=e/2.0;
        for(int i=0;i<outnum;i++){
            fa2[i]=fa2[i]+rate*ss[i];
        }
        for(int i=0;i<hidenum;i++){
            fa1[i]=fa1[i]+rate*yy[i];
        }
    }
}
void ans(){

     for(int i=0;i<hidenum;i++){
        o1[i]=0.0;
        for(int j=0;j<innum;j++){
            o1[i]=o1[i]+w1[j][i]*m[j];
        }
        //x1[i]=2.0/(1.0+exp(-o1[i]+fa1[i]))-1.0;
        x1[i]=1/(1+exp(-o1[i]-fa1[i]));
     }
     for(int i=0;i<outnum;i++){
        o2[i]=0.0;
        for(int j=0;j<hidenum;j++){
            o2[i]=o2[i]+w2[j][i]*x1[j];
        }
        //x2[i]=2.0/(1.0+exp(-o1[i]+fa2[i]))-1.0;
        x2[i]=1/(1+exp(-o2[i]-fa2[i]));
     }
}
int main()
{
    init();
    int c=0;
    while(error>0.00001&&c<1000000){
        e=0.0;
        c++;
        train();
        //cout<<error<<" "<<c<<" "<<endl;
    }
    printf("train finished\n");
    cout<<ct<<endl;
    printf("number of test:");
    int TT;
    scanf("%d",&TT);
    while(TT--){
        scanf("%lf",&m[0]);
        printf("should:%.7lf\n",2*sin(m[0])-0.7);
        ans();
        cout<<"output:";
    for(int i=0;i<outnum;i++){
        cout<<setprecision(8)<<x2[i]*2.0<<" 误差："<<fabs(x2[i]*2.0-(2*sin(m[i])-0.7));
    }
    cout<<endl;
    }
    return 0;
}
