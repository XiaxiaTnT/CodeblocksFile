#include<stdio.h>
unsigned fun(unsigned w)
{
    unsigned t=w;
    list<int> l=new list;
    while(t!=0){
        unsigned m=t%10;
        unsigned t/=10;
        list.insert(0,m);
    }
}
int main()
{
	 unsigned  c;
	 printf("����һ���޷�����:\n");
	 scanf("%d",&c);
     printf("%d\n",fun(c));
     return 0;
}
