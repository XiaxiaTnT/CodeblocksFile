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
#include<iomanip>
#include <stack>
using namespace std;
typedef long long LL;
const int INF=0x7fffffff;
const int MAX_N=60;

int num_of_edge,num_of_v;
int num_of_jihe;
int num_of_start,num_of_end,num_of_final;
int res[10000][10];
int startnode[100];
int endnode[100];
int finalnode[100];

struct edge{
    int to;
    char v;
    edge(int a,char b){
        to=a;
        v=b;
    }
};

vector<edge>G[MAX_N];
map<int,int>s;
map<int,int>::iterator a;
int vis[MAX_N];
char V[10];



void change(int ans){//将一个集合输出
    int cur=ans;
    int p=0;
    if(ans==0){
        printf("( NULL )");
        return;
    }
    printf("( ");
    while(cur>0){
        if(cur&1==1)printf("%d ",p);
        cur>>=1;
        p++;
    }
    printf(")");
}



int dfs(int from,char key){//from代表从编号为from的点开始dfs，key代表要经过的权值
    int ans=0;//初始化集合为空

    if(key=='0'){//如果要dfs空
        for(int i=0;i<G[from].size();i++){
            if(G[from][i].v==key&&vis[G[from][i].to]==0){
                ans|=(1<<G[from][i].to);//把要去的点并进集合
                vis[G[from][i].to]=1;//为了避免重复将走过的点标记为1，没走过的再走
                ans|=dfs(G[from][i].to,key);//递归地调用dfs
            }
        }
        ans|=(1<<from);//不能落下起点啊
    }

    else{//这是dfs权值不为0的路径，因为只走一步，并且自己不算集合里，所以不用递归，最后也不用并起点
        for(int i=0;i<G[from].size();i++){
            if(G[from][i].v==key){
                ans|=(1<<G[from][i].to);
            }
        }
    }
    return ans;
}

void bfs(){
    queue<int>q;
    int a=0;
    for(int i=0;i<num_of_start;i++){
        a|=dfs(startnode[i],'0');
    }
    q.push(a);
    int n=1;
    s.insert(make_pair(a,n++));


    while(!q.empty()){
        int f=q.front();
        q.pop();
        num_of_jihe++;
        res[num_of_jihe][0]=f;
        for(int i=0;i<num_of_v;i++){
            int cur=f;
            int p=0;
            int ans=0;
            while(cur>0){
                if(cur&1==1)ans|=dfs(p,V[i]);
                p++;
                cur>>=1;
            }

            cur=ans;
            p=0;
            ans=0;
            while(cur>0){
                memset(vis,0,sizeof(vis));
                if(cur&1==1)ans|=dfs(p,'0');
                p++;
                cur>>=1;
            }

            res[num_of_jihe][i+1]=ans;
//            change(ans);
            if(s.find(ans)==s.end()&&ans!=0){

                q.push(ans);
                s.insert(make_pair(ans,n++));
//                change(ans);
//                cout<<"插入ans："<<endl;
            }
        }
    }
}




void input(){
    printf("******************************* NFA—DFA转化 ***********************************\n");
    printf("请输入边的个数：");
    scanf("%d",&num_of_edge);
    printf("请输入弧转换种类个数：");
    scanf("%d",&num_of_v);
    printf("请输入%d个字母代表不同的弧转换类型(空不计算)：",num_of_v);
    for(int i=0;i<num_of_v;i++){
        scanf(" %c",&V[i]);
    }
    printf("输入起始点的个数：");
    scanf("%d",&num_of_start);
    printf("输入这%d个起始点的编号(用空格隔开)：",num_of_start);
    for(int i=0;i<num_of_start;i++){
        scanf("%d",&startnode[i]);
    }
    printf("输入终止点的个数：");
    scanf("%d",&num_of_end);
    printf("输入这%d个终止点的编号(用空格隔开)：",num_of_end);
    for(int i=0;i<num_of_end;i++){
        scanf("%d",&endnode[i]);
    }
    printf("下列%d行每行输入3个值，分别代表结点的起点、终点、弧转换方式(方式为空输入0)，用空格隔开\n",num_of_edge);
    for(int i=1;i<=num_of_edge;i++){
        int from,to;
        char v;
        scanf("%d%d %c",&from,&to,&v);
        G[from].push_back(edge(to,v));
    }

}

void init(){
    num_of_jihe=0;
    num_of_final=0;
    memset(vis,0,sizeof(vis));
    memset(res,0,sizeof(res));
    s.clear();
    s.insert(make_pair(0,0));
    for(int i=0;i<MAX_N;i++)G[i].clear();
}

void output(){
    //生成txt
    FILE *f=NULL;
    f=fopen("C:\\data.txt","w");
    //f=fopen("G:\\vs文件\\read\\read\\bin\\Debug\\data.txt","w");
    if(f==NULL){printf("error!\n输出文件失败\n");return;}

    fprintf(f,"%d\n",num_of_v);
    for(int i=0;i<num_of_v;i++){
        fprintf(f,"%c",V[i]);
    }
    fprintf(f,"\n%d",num_of_jihe);
//    fprintf(f,"\n%d\n",num_of_start);
//    for(int i=0;i<num_of_start;i++){
//        fprintf(f,"%d ",startnode[i]);
//    }
//    fprintf(f,"\n%d\n",num_of_end);
//    for(int i=0;i<num_of_end;i++){
//        fprintf(f,"%d ",endnode[i]);
//    }


    printf("\nOutput:\n\n");
    printf("0             ");
    for(int i=0;i<num_of_v;i++){
        cout<<left<<setw(14)<<V[i];
    }
    printf("\n");
    for(int i=1;i<=num_of_jihe;i++){
        a=s.find(res[i][0]);
        cout<<"node"<<left<<setw(10)<<a->second;
        fprintf(f,"\n%d ",a->second);
        for(int j=1;j<=num_of_v;j++){
            a=s.find(res[i][j]);
            cout<<"node"<<left<<setw(10)<<a->second;
            fprintf(f,"%d ",a->second);
        }
        printf("\n");
    }

    printf("\nnode0");
    change(0);
    printf("\n");
    for(int i=1;i<=num_of_jihe;i++){
        printf("node%d",i);
        change(res[i][0]);
        if(i==1)printf("起始点！");
        for(int j=0;j<num_of_end;j++){
            if((res[i][0]>>endnode[j])&1==1){
                printf("终止点！");
                finalnode[num_of_final++]=i;
                break;
            }
        }

        printf("\n");
    }

    fprintf(f,"\n%d\n",num_of_final);
    for(int i=0;i<num_of_final;i++){
        fprintf(f,"%d ",finalnode[i]);
    }

    printf("\nProgram running successfully\n");
    printf("生成data文件成功\n\n\n");
    fclose(f);
    f=NULL;
}

int main(){

    while(1){
        init();
        input();
        bfs();
        output();

    }
    return 0;
}

/*
测试数据

13
2
a b
1
0
1
10
0 1 0
1 2 0
1 4 0
2 3 a
4 5 b
3 6 0
5 6 0
6 1 0
0 7 0
6 7 0
7 8 a
8 9 b
9 10 b

20
3
a b c
1
0
1
14
0 1 0
0 10 0
1 3 a
1 2 b
2 4 c
4 10 0
3 5 a
4 6 c
5 7 0
7 6 b
10 8 a
6 9 a
6 8 b
8 11 c
11 12 a
12 9 0
8 13 b
9 13 a
9 1 0
13 14 c
*/
