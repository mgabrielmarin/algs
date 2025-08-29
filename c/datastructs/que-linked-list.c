#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct que {
  struct node *rear;
  struct node *front;
};

struct node *init_node(int val) {
  struct node *n = malloc(sizeof(struct node));
  n->val = val;
  n->next = NULL;
  return n;
}

struct que *init_que() {
  struct que *q = malloc(sizeof(struct que));
  q->rear = q->front = NULL;
  return q;
}

int is_empty(struct que *q) {
  return q->front == NULL;
}

void enque(struct que *q, int val) {
  struct node *n = init_node(val);
  if(is_empty(q)) {
    q->rear = q->front = n;
  } else {
    q->rear->next = n;
    q->rear = n;
  }
}

void deque(struct que *q) {
  if(is_empty(q))
    return;
  struct node *tmp = q->front;
  q->front = q->front->next;
  if(q->front == NULL) q->rear = NULL;
  free(tmp);
}

void print_que(struct que *q) {
  struct node *tmp = q->front;
  if(tmp == NULL) return;
  while(tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
  printf("\n");
}

int main(int argc, char **argv) {
  struct que *q = init_que();

  enque(q, 10);
  enque(q, 20);
  enque(q, 30);
  print_que(q);

  deque(q);
  print_que(q);

  deque(q);
  deque(q);
  print_que(q);
    
  return 0;
}
