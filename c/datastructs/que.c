#include <stdio.h>
#include <stdlib.h>

#define MAXQUE 32

struct que {
  int arr[MAXQUE];
  int back;
  int front;
};

void init(struct que *q) {
  q->back = 0;
  q->front = -1;
}

int is_empty(struct que *q) {
  return q->back - 1 == q->front ? 1 : 0;
}

int is_full(struct que *q) {
  return q->back == MAXQUE;
}

void enque(struct que *q, int val) {
  if(is_full(q)) {
    perror("Que full");
    return;
  }
  q->arr[q->back++] = val;
}

void deque(struct que *q) {
  if(is_empty(q)) {
    perror("Que empty");
    return;
  }
  q->front++;
}

int peek(struct que *q) {
  if(is_empty(q)) {
    perror("Que empty");
    return -1;
  }
  return q->arr[q->front+1];
}

void print(struct que *q) {
  if(is_empty(q)) {
    perror("Que empty");
    return;
  }
  for(int i = q->front + 1; i < q->back; i++)
    printf("%d ", q->arr[i]);
  printf("\n");
}

int main(int argc, char **argv) {
  struct que q;
  init(&q);
  
  enque(&q, 2);
  print(&q);

  enque(&q, 5);
  print(&q);

  enque(&q, 10);
  print(&q);

  printf("%d\n", peek(&q));
  
  deque(&q);
  print(&q);

  printf("%d\n", peek(&q));
  
  return 0;
}
