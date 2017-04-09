#include<stdio.h>
void hanoi ( int n, char a,  char b,  char c )
  {  if  ( n >= 1 )
         {  hanoi ( n-1,  a,  c,  b ) ;
             printf("%c -->  %c\n", a , c) ;
             hanoi ( n-1,  b,  a,  c ) ;
          }
  }
int  main ()
  {  int  n ;
      printf( " Input the number of diskes:\n " ) ;
      scanf("%d",&n) ;
      hanoi ( n,  'A' ,  'B' , 'C' ) ;
      return 0;
  }
