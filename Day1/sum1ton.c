#include<stdio.h>

int main()
{
int i, n = 9, sum = 0;

for(i=1;i<=n;i++)
	sum += i;

printf("Sum from 1 to %d is: %d\n",n,sum);

return 0;
}
