#include<stdio.h>

extern int load(int x, int y);

int main()
{
int sum  = 0;
int cnt = 9;
sum = load(0x0, cnt+1);
printf("Sum from 1 to %d is: %d\n",cnt,sum);

return 0;
}
