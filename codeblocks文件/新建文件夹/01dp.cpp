#include<iostream>
using namespace std;
#define MAX 100
int a[MAX][MAX];
struct A{
   int value;
   int weight;
};
A Array[MAX];
void package(int c,int n){
    for(int i=0;i<c+1;i++){
            for(int j=0;j<=n+1;j++){
        a[i][j]=0;
            }
    }
    for(int i=1;i<c+1;i++){
        int C=i;
        for(int j=n;j>0;j--){
            if(Array[j].weight<=i){
                if((a[j+1][i-Array[j].weight]+Array[j].value>a[j+1][i])&&(C-Array[j].weight)>0){
                    a[j][i]=a[j+1][C-Array[j].weight]+Array[j].value;
                    C-=Array[j].weight;
                }
                else if(Array[j].value>a[j+1][i]){
                a[j][i]=Array[j].value;
                C-=Array[j].weight;
            }
                else
                    a[j][i]=a[j+1][i];
            }

            else
                a[j][i]=a[j+1][i];
        }
    }
}
int main(){
    Array[1].value=6;
    Array[1].weight=2;
    Array[2].value=3;
    Array[2].weight=2;
    Array[3].value=5;
    Array[3].weight=6;
    Array[4].value=4;
    Array[4].weight=5;
    Array[5].value=6;
    Array[5].weight=4;
    package(10,5);
  //  cout<<a[1][10]<<endl;
    for(int i=1;i<6;i++){
        for(int j=1;j<11;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
