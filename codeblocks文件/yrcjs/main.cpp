#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;

struct P{
	int d;	//���g(n)
	int w;	//����λ��h(n)
	int id;	//��¼�ýڵ��id���������ʱ�ҵ��ýڵ�
	string s;	//״̬
	friend bool operator <(const P &a,const P &b){//��f(n)=g(n)+h(n)��С����
		return a.d+a.w>b.d+b.w;  //����
	}
}p;
int m,n;
int num;
const string t="000";
string stack[1000000];		//��¼�����еĽڵ�
string record[1000000];		//����㿪ʼ��¼��·��
int father[10000000];		//��¼�ýڵ�ĸ��ڵ�
int top=0;					//stack��ָ��
priority_queue<P> pq;		//open��
map<string,bool> mp;		//��¼��״̬�Ƿ��Ѿ����ʹ���1���ʹ���0û��

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
int solve()	//��������
{
	P cur;
	cur=pq.top();
	int ppp=check(cur.s);
	if(ppp==-1)return -1;
	while(!pq.empty()){
		cur=pq.top(); //open��
		//cout<<cur.s<<endl;
		pq.pop();
		if(cur.s==t) return cur.id;	//�ﵽĿ��״̬�����ص�ǰ�ڵ��id
		int r=cur.id;
		if(cur.s[2]=='1'){          //�ո�������
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
	return -1;	//����ʧ��
}

void print(int x)////��record���������ǰ�����Ľڵ�
{
	printf("(%c,%c,%c) (%d,%d)",record[x][0],record[x][1],record[x][2],m-int(record[x][0]-'0'),n-int(record[x][1]-'0'));
	printf("\n");
}
int main()
{
//	freopen("a.txt","r",stdin);
	int tt;	//���Ե�����
	cin>>tt;
	for(int k=1;k<=tt;k++){
		cout<<"Case "<<k<<":\n";
		int i,j;
		char a;
		p.s="";
		cout<<"����ʿ��";
		cin>>m;
		cout<<"Ұ��:";
		cin>>n;
		p.s+=m+'0';
		p.s+=n+'0';
		p.s+='1';
		cout<<"������:";
		cin>>num;
		p.d=0,p.w=calw(p.s),p.id=0;
		father[0]=-1;
		mp[p.s]=1;
		stack[0]=p.s;
		pq.push(p);	//��open���м����ʼ״̬�ڵ�
		int id=solve();//������������
		if(id==-1){
			cout<<"�޽⣡\n";
		}else{
			int c=-1;
			while(id>=0){	//��stack�д�Ľڵ㰴������뵽record��
				record[++c]=stack[id];
				id=father[id];
			}
			cout<<"��ʼ״̬��"<<endl;
			print(c); //�����ʼ�ڵ�
			cout<<"�ƶ�����: \n";
			for(i=c-1;i>=0;i--){
				cout<<"Step "<<c-i<<":\n";//�����ǰ��������
				print(i);//�����ǰ�����Ľڵ�
			}
			cout<<"�ƶ�������\n";
		}
		mp.clear();
		while(!pq.empty()) pq.pop();
		top=0;
		cout<<endl;
	}
	system("pause\n");
	return 0;
}
