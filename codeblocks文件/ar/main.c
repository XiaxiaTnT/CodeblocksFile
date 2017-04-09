#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char ElementType;
typedef struct TreeNode *PtrToNode;
typedef  PtrToNode Tree;
struct TreeNode
{
    ElementType Elemnet;
    Tree Left;
    Tree Right;
};
int main()
{
    Tree T1=new Tree;
    return 0;
}
