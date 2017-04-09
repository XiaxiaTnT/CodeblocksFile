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



void change(int ans){//��һ���������
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



int dfs(int from,char key){//from����ӱ��Ϊfrom�ĵ㿪ʼdfs��key����Ҫ������Ȩֵ
    int ans=0;//��ʼ������Ϊ��

    if(key=='0'){//���Ҫdfs��
        for(int i=0;i<G[from].size();i++){
            if(G[from][i].v==key&&vis[G[from][i].to]==0){
                ans|=(1<<G[from][i].to);//��Ҫȥ�ĵ㲢������
                vis[G[from][i].to]=1;//Ϊ�˱����ظ����߹��ĵ���Ϊ1��û�߹�������
                ans|=dfs(G[from][i].to,key);//�ݹ�ص���dfs
            }
        }
        ans|=(1<<from);//����������㰡
    }

    else{//����dfsȨֵ��Ϊ0��·������Ϊֻ��һ���������Լ����㼯������Բ��õݹ飬���Ҳ���ò����
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
//                cout<<"����ans��"<<endl;
            }
        }
    }
}




void input(){
    printf("******************************* NFA��DFAת�� ***********************************\n");
    printf("������ߵĸ�����");
    scanf("%d",&num_of_edge);
    printf("�����뻡ת�����������");
    scanf("%d",&num_of_v);
    printf("������%d����ĸ����ͬ�Ļ�ת������(�ղ�����)��",num_of_v);
    for(int i=0;i<num_of_v;i++){
        scanf(" %c",&V[i]);
    }
    printf("������ʼ��ĸ�����");
    scanf("%d",&num_of_start);
    printf("������%d����ʼ��ı��(�ÿո����)��",num_of_start);
    for(int i=0;i<num_of_start;i++){
        scanf("%d",&startnode[i]);
    }
    printf("������ֹ��ĸ�����");
    scanf("%d",&num_of_end);
    printf("������%d����ֹ��ı��(�ÿո����)��",num_of_end);
    for(int i=0;i<num_of_end;i++){
        scanf("%d",&endnode[i]);
    }
    printf("����%d��ÿ������3��ֵ���ֱ���������㡢�յ㡢��ת����ʽ(��ʽΪ������0)���ÿո����\n",num_of_edge);
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
    //����txt
    FILE *f=NULL;
    f=fopen("C:\\data.txt","w");
    //f=fopen("G:\\vs�ļ�\\read\\read\\bin\\Debug\\data.txt","w");
    if(f==NULL){printf("error!\n����ļ�ʧ��\n");return;}

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
        if(i==1)printf("��ʼ�㣡");
        for(int j=0;j<num_of_end;j++){
            if((res[i][0]>>endnode[j])&1==1){
                printf("��ֹ�㣡");
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
    printf("����data�ļ��ɹ�\n\n\n");
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
��������

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
