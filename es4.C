#include <stdio.h>
int fun(int b, int x)
{int s=0, i=1;
while (x>0)
{s=s+i*(x%b); x=x/(b*b); i=i*b; }
return s;
}
int g(int b, int x) {return fun(b, x/b) - fun(b,x);}
int main()
{printf("1) %i\n", fun(9, 102));
printf("2) %i\n", g(9, 102));
}