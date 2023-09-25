#include<stdio.h>
#include<math.h>

int main()
{
long long int a = (long long int)(pow(2,63) - 1);
long long int b = (long long int)(pow(2,63) * - 1);


printf("Highest integer  = %lld, Lowest integer = %lld",a,b);

return 0;
}
