#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;

struct P{
	int d;	//深度g(n)
	int w;	//不在位数h(n)
	int id;	//记录该节点的id，用于输出时找到该节点
	string s;	//状态
	friend bool operator <(const P &a,const P &b){//按f(n)=g(n)+h(n)大小排序
		return a.d+a.w>b.d+b.w;  //最大堆
	}
}p;
int m,n;
int num;
const string t="000";
string stack[1000000];		//记录搜索中的节点
string record[1000000];		//从起点开始记录解路径
int father[10000000];		//记录该节点的父节点
int top=0;					//stack的指针
priority_queue<P> pq;		//open表
map<string,bool> mp;		//记录该状态是否已经访问过：1访问过，0没有

int calw(string s)
{
	int re=0;
	for(int i=0;i<2;i++){
        re+=(s[i]-'0');
	}
	re-=(s[2]-'0')*2;
	return re;
}
int check(string s){
    if(s[0]<s[1])return -1;
    if(num<=1)return -1;
    return 0;
}
int solve()	//搜索过程
{
	P cur;
	cur=pq.top();
	int ppp=check(cur.s);
	if(ppp==-1)return -1;
	while(!pq.empty()){
		cur=pq.top(); //open表
		//cout<<cur.s<<endl;
		pq.pop();
		if(cur.s==t) return cur.id;	//达到目标状态，返回当前节点的id
		int r=cur.id;
		if(cur.s[2]=='1'){          //空格向上移
			p.s=cur.s;
			/*for(int i=0;i<=num;i++){
                    for(int j=0;j<=num-i;j++){
                         if((i==0||i>=j)&&(p.s[0]-i-'0'>=0)&&(p.s[1]-j-'0'>=0)){
                            p.s[0]=cur.s[0]-i;
                            p.s[1]=cur.s[1]-j;
                            p.s[2]='0';
                            if(!mp[p.s]){
				              p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
                              pq.push(p);
				              stack[++top]=p.s;
                              father[top]=r;
                             mp[p.s]=1;
			}
                         }

                    }
			}*/

			for (int x = 0; x <=m; x++) {
				for (int y = 0; y <= num - x && (y <= x || x == 0); y++) {
					if (x != 0 || y != 0) {
						if (int(cur.s[0] - '0') - x >= 0 && int(cur.s[1] - '0') - y >= 0 )
							if (int(cur.s[0] - '0') - x >= int(cur.s[1] - '0') - y || int(cur.s[0] - '0') - x == 0) {
								if (m - int(cur.s[0] - '0') + x >= n - int(cur.s[1] - '0') + y || m - int(cur.s[0] - '0') + x == 0) {

									p.s[0]=cur.s[0]  - x;
									p.s[1]=cur.s[1]  - y;
									p.s[2]='0';
									if (!mp[p.s]) {
										p.d = cur.d + 1, p.w = calw(p.s), p.id = top + 1;
										pq.push(p);
										stack[++top] = p.s;
										father[top] = r;
										mp[p.s] = 1;
									}
								}
							}
					}
				}
			}
		}
		if(cur.s[2]=='0'){
           p.s=cur.s;
           for (int x = 0; x <= m; x++) {
				for (int y = 0; y <= num - x && (y <= x || x == 0); y++) {
					if (x != 0 || y != 0) {
						if (m - int(cur.s[0] - '0') - x >= 0 && n - int(cur.s[1] - '0')-y >= 0)
							if (int(cur.s[0] - '0') + x >= int(cur.s[1] - '0') + y || int(cur.s[0] - '0') + x == 0) {
								if (m - int(cur.s[0] - '0') - x >= n - int(cur.s[1] - '0') - y || m- int(cur.s[0] - '0') - x == 0) {
									p.s[0]=cur.s[0]+x;
                                    p.s[1]=cur.s[1]+y;
                                    p.s[2]='1';
									if (!mp[p.s]) {
										p.d = cur.d + 1, p.w = calw(p.s), p.id = top + 1;
										pq.push(p);
										stack[++top] = p.s;
										father[top] = r;
										mp[p.s] = 1;
									}
								}
							}
					}
				}
			}
			/*for(int i=0;i<num;i++){
                    for(int j=0;j<num-i;j++){
                         if((!(i==0&&j==0))&&(p.s[3]-i-'0'>=0)&&(p.s[4]-j-'0'>=0)&&(i==0||i>=j)&&(p.s[3]-i-'0'>=p.s[4]-j-'0'>=0)){
                            p.s[0]=cur.s[0]+i;
                            p.s[1]=cur.s[1]+j;
                            p.s[2]='1';
                            if(!mp[p.s]){
				              p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
                              pq.push(p);
				              stack[++top]=p.s;
                              father[top]=r;
                             mp[p.s]=1;
			}
                         }

                    }
			}*/
		}

	}
	return -1;	//搜索失败
}

void print(int x)////从record表中输出当前搜索的节点
{
	printf("(%c,%c,%c) (%d,%d)",record[x][0],record[x][1],record[x][2],m-int(record[x][0]-'0'),n-int(record[x][1]-'0'));
	printf("\n");
}
int main()
{
//	freopen("a.txt","r",stdin);
	int tt;	//测试的组数
	cin>>tt;
	for(int k=1;k<=tt;k++){
		cout<<"Case "<<k<<":\n";
		int i,j;
		char a;
		p.s="";
		cout<<"传教士：";
		cin>>m;
		cout<<"野人:";
		cin>>n;
		p.s+=m+'0';
		p.s+=n+'0';
		p.s+='1';
		cout<<"船荷载:";
		cin>>num;
		p.d=0,p.w=calw(p.s),p.id=0;
		father[0]=-1;
		mp[p.s]=1;
		stack[0]=p.s;
		pq.push(p);	//往open表中加入初始状态节点
		int id=solve();//调用搜索过程
		if(id==-1){
			cout<<"无解！\n";
		}else{
			int c=-1;
			while(id>=0){	//把stack中存的节点按次序放入到record中
				record[++c]=stack[id];
				id=father[id];
			}
			cout<<"起始状态："<<endl;
			print(c); //输出初始节点
			cout<<"移动过程: \n";
			for(i=c-1;i>=0;i--){
				cout<<"Step "<<c-i<<":\n";//输出当前搜索步骤
				print(i);//输出当前搜索的节点
			}
			cout<<"移动结束！\n";
		}
		mp.clear();
		while(!pq.empty()) pq.pop();
		top=0;
		cout<<endl;
	}
	system("pause\n");
	return 0;
}
