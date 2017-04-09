#include<iostream>
using namespace std;
#define MAX_size 10000
int p[MAX_size];
int m[MAX_size][MAX_size];
int s[MAX_size][MAX_size];
int n;
void MatrixChain(){
for(int i=1;i<=n;i++)m[i][i]=0;
for(int r=2;r<=n;r++){
    for(int i=1;i<=n-r+1;i++){
        int j=i+r-1;
        m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
        s[i][j]=i;
        for(int k=i+1;k<j;k++){
            int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            if(t<m[i][j]){
                m[i][j]=t;
                s[i][j]=k;
            }
        }
    }
}
}
void Traceback(int i,int j){
if(i==j)return;
Traceback(i,s[i][j]);
Traceback(s[i][j]+1,j);
cout<<"Multiply A"<<i<<","<<s[i][j];
cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}
int main(){
    cout<<"请输入矩阵个数：";
    cin>>n;
    cout<<"请按顺序输入矩阵维数"<<endl;
    cout<<"（前两个为第一个个矩阵的行数和列数，之后只需输入列数）"<<endl;
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    MatrixChain();
    cout<<"请输入要查询的矩阵所在的两个位置";
    int a1,a2;
    cin>>a1>>a2;
    cout<<"所需的最小数乘次数为："<<m[a1][a2]<<endl;
    cout<<"最优计算次序为："<<endl;
    Traceback(a1,a2);
    //30 35 15 5 10 20 25


}
