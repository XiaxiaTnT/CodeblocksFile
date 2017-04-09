#include<iostream>
using namespace std;
const int Max=10000;
int m,n;
char x[Max],y[Max];
int c[Max][Max],b[Max][Max];
void LCSLength(){
    int i,j;
    for(i=0;i<=m;i++)c[i][0]=0;
    for(i=1;i<=n;i++)c[0][i]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(x[i]==y[j]){c[i][j]=c[i-1][j-1]+1;b[i][j]=1;}
            else if(c[i-1][j]>=c[i][j-1]){c[i][j]=c[i-1][j];b[i][j]=2;}
            else{c[i][j]=c[i][j-1];b[i][j]=3;}
        }
    }
}
void LCS(int i,int j){
    if(i==0||j==0)return;
    if(b[i][j]==1){LCS(i-1,j-1);cout<<x[i]<<" ";}
    else if(b[i][j]==2)LCS(i-1,j);
    else LCS(i,j-1);
}
int main(){
    cout<<"������x���е�Ԫ�ظ�����";
    cin>>m;
    cout<<"������Ԫ�أ�"<<endl;
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    cout<<"������y���е�Ԫ�ظ�����";
    cin>>n;
    cout<<"������Ԫ�أ�"<<endl;
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    LCSLength();
    cout<<"������г���Ϊ�� "<<c[m][n]<<endl;
    cout<<"�������Ϊ��"<<endl;
    LCS(m,n);
    return 0;
    //A B C B D A B
    //B D C A B A
}
