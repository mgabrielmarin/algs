#include <stdio.h>

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(char *string, int sSize)
{
  for(int i = 0; i < sSize / 2 - 1; ++i)
    swap(string + i, string + sSize - i - 2);
}

int main(void)
{
  char string[] = "Hello";
  int length = sizeof(string) / sizeof(string[0]);
  printf("%s\n", string);
  reverse(string, length);
  printf("%s\n", string);
}
