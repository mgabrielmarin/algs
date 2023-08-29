#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMSLEN 13

typedef struct {
  char* sym;
  int val;
} numeral;

numeral nums[NUMSLEN] = {
  {"I", 1},
  {"IV", 4},
  {"V", 5},
  {"IX", 9},
  {"X", 10},
  {"XL", 40},
  {"L", 50},
  {"XC", 90},
  {"C", 100},
  {"CD", 400},
  {"D", 500},
  {"CM", 900},
  {"M", 1000}
};

int from_roman(char* roman);
void to_roman(int number, char* destination);

int main(int argc, char** argv)
{
  char* dest = malloc(20 * sizeof(char));
  to_roman(749, dest);
  int num = from_roman(dest);
  printf("%s\n", dest);
  printf("%i\n", num);

  return 0;
}

int from_roman(char* roman)
{
  int len = strlen(roman);
  int res = 0;
  for(int i = 0; i < len; ++i) {
    char temp[2];
    strncpy(temp, &roman[i],2);
    for(int j = NUMSLEN - 1; j >= 0; --j) {
      if(!strncmp(temp,nums[j].sym, 2)) {
        res += nums[j].val;
        i += 1;
        break;
      } else if(roman[i] == *(nums[j].sym) && strlen(nums[j].sym) == 1) {
        res += nums[j].val;
        break;
      }
    }
  }
  return res;
}

void to_roman(int number, char* destination)
{
  int current_index =  NUMSLEN - 1;
  while(number) {
    if(number >= nums[current_index].val) {
      number -= nums[current_index].val;
      strcat(destination, nums[current_index].sym);
    }
    else current_index--;
  }
}

