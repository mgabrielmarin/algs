#include <stdio.h>
#include <math.h>
#include <limits.h>

int length(int x)
{
  int res = 0;
  while(x) {
    res += 1;
    x /= 10;
  }
  return res;
}

int reverse(int x)
{
  long int res = 0;
  int len = length(x);

  for(int i = len - 1; i >= 0; --i) {
    res += (x % 10) * pow(10, i);
    x /= 10;
  }

  if(res <  INT_MIN || res > INT_MAX )
    return 0;
  return res;
}

int main(int argc, char **argv)
{
  int x = 321;
  printf("%d\n", reverse(x));

  return 0;
}
