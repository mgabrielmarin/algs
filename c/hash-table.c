/*



*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct DataItem {
  int data;
  int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;

int hashCode(int key);
struct DataItem *search(int key);
void insert(int key, int data);
struct DataItem *delete(struct DataItem *item);
void display();

int hashCode(int key) {
  return key % SIZE;
}

struct DataItem *search(int key)
{
  int hashIndex = hashCode(key);
  while(hashArray[hashIndex] != NULL) {
    if(hashArray[hashIndex]->key == key)
      return hashArray[hashIndex];
    ++hashIndex;
    hashIndex %= SIZE;
  }
  return NULL;

}

void insert(int key, int data) 
{
  struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
  item->key = key;
  item->data = data;
  int hashIndex = hashCode(key);
  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
    ++hashIndex;
    hashIndex %= SIZE;
  }
  hashArray[hashIndex] = item;

}

struct DataItem *delete(struct DataItem *item)
{
  int key = item->key;
  int hashIndex = hashCode(key);

  // move array until empty
  while(hashArray[hashIndex] != NULL) {
    if(hashArray[hashIndex]->key == key) {
      struct DataItem *temp = hashArray[hashIndex];
      hashArray[hashIndex] = dummyItem;
      return temp;
    }
    ++hashIndex;
    hashIndex %= SIZE;
  }
  return NULL;
}

void display()
{
  for (int i = 0; i < SIZE; i += 1)
    if(hashArray[i] != NULL)
      printf("(%d,%d)", hashArray[i]->key, hashArray[i]->data);
    else
      printf(" ~~ ");
  printf("\n");
}

int main(int argc, char **argv)
{
  dummyItem = (struct DataItem *)malloc(sizeof(struct DataItem));
  dummyItem->key = -1;
  dummyItem->data = -1;

  insert(1, 20);
  insert(2, 70);

  display();

  return 0;
}
