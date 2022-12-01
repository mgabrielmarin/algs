/*

x^2 - 4 * y^2 = n --> a = 1, b = -4, c = n
find the pairs of x and y that satisfy this eq when n is given

ex:
solEquaStr(5) -> {{3,1}}

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pair Pair;
struct Pair {
  long long first;
  long long snd;
};

// Fill length with the number of pairs in your array of pairs.
Pair** solEquaStr(long long n, int* length);

int main(int argc, char* argv[])
{
  int len = 0;
  Pair** res = solEquaStr(5, &len);

  return 0;
}

Pair** solEquaStr(long long n, int* length)
{
  Pair** res = NULL;
  long long i,j,x,y;
  for(long long i = 1; i <= (long long)sqrt(n); ++i) {
    if(n%i == 0) {
      j = n / i;
      if(((i+j) % 2 == 0) && ((j-i) % 4 == 0)) {
        x = (i + j) / 2;
        y = (j - i) / 4;
        (*length)++;
        *res = realloc(res, *length * sizeof(Pair));
        (*res)[*length-1].first = malloc(sizeof(long long));
        (*res)[*length-1].first = x;
      }
    }
  }
  return res;
}
