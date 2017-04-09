#include <iostream>
using namespace std;
typedef struct {
    int a;
    int b;
}ball;
ball Ball[1010];
int N;
int M;
void swap(int i){
    int t=Ball[i].a;
    Ball[i].a=Ball[i].b;
    Ball[i].b=t;
}
int main()
{
    int n=0;
    cin>>n;
    while(n--){
        cin>>N>>M;
        for(int i=0;i<N;i++){
            cin>>Ball[i].a>>Ball[i].b;
        }
    }
    return 0;
}
