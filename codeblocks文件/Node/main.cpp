#include<stdio.h>
#include<stdlib.h>

typedef struct TNode
{
    char data;
    struct TNode *lchild,*rchild;
}Bitnode,*Bitree;
void CreatTree(Bitree &T)
{
    char ch;
	scanf(" %c",&ch);
	//getchar();
    if(ch=='#'){
         T=NULL;
    }

    else {
        T=(Bitree)malloc(sizeof(Bitnode));
		if(!T) exit(1);
        T->data=ch;
        CreatTree(T->lchild);
        CreatTree(T->rchild);
}
}

void Preorder(Bitree p,char B[20][20],int i,int j,int t){
	if(p!=NULL){
		B[i][j]=p->data;
		//i+=3;j-=3;
		i+=t;j-=t;
		Preorder(p->lchild,B,i,j,t-1);
		if(p->lchild){
                for(int k=1;k<t;k++){
                    B[i-k][j+k]='/';
                }
		//B[i-1][j+1]='/';
		//B[i-2][j+2]='/';
		}
		i=i;j+=2*t;
		Preorder(p->rchild,B,i,j,t-1);
		if(p->rchild){
                for(int k=1;k<t;k++){
                    B[i-k][j-k]='\\';
                }
		//B[i-1][j-1]='\\';
		//B[i-2][j-2]='\\';
		}
	}
}

int  main()
{	char B[20][20];

	int i,j;
	Bitree T;
	CreatTree(T);
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			B[i][j]=' ';
    int t;
    printf("Ê÷µÄ²ãÊý£º");
    scanf("%d",&t);
	Preorder(T,B,0,10,t);
	for(i=0;i<(1+t)*t/2;i++){
		for(j=0;j<20;j++)
			printf("%c",B[i][j]);
	printf("\n");
}
return 0;
}
