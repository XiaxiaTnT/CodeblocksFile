#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define length 1000
#define range 1000
void swap(int *a,int *b){
int t;
t=*a;
*a=*b;
*b=t;
}
int Part(int a[],int p,int r){
int i=p,j=r+1;
int x=a[p];
while(1)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a[i],a[j]);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}
void quicksort(int a[],int p,int r){
if(p<r){
    int q=Part(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
}
}

int partition(int a[],int p,int r,int x)
{
	int i=p-1,j=r+1;
	while(1)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a[i],a[j]);
	}

	return j;
}

int Select(int a[],int p,int r,int k)
{
	int i,j,x;int ii;
	if(r-p<75)
	{
	    quicksort(a,a[p],a[r]);
		return a[p+k-1];
	}
	for(  ii=0;ii<=(r-p-4)/5;ii++)
	{
		quicksort(a,a[p+5*ii],a[p+5*ii+4]);
		swap(a[p+ii],a[p+5*ii+2]);
	}
	x=Select(a,p,p+(r-p-4)/5,(r-p-4)/10);
    i=partition(a,p,r,x);
	j=i-p+1;
	if(k<=j)return Select(a,p,i,k);
	else return Select(a,i+1,r,k-j);
}
int main()
{
	int a[length];
	int i,t,x;
	for(i=1;i<1000;i++)
	{
		a[i]=rand()%1000+1;
		printf("%5d",a[i]);
	}
    printf("\n输入要查找第几小元素\n");
	scanf("%d",&t);
	printf("%d\n",t);
	x=Select(a,1,length-1,t);
	printf("第%d小的元素为:%d\n",t,x);
	printf("%d",t);
}
