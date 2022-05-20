/*

Stack implementation using linked lists

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
  int val;
  struct sNode *next;
} sNode;

sNode *newNode(int val);
int isEmpty(sNode *root);
int peek(sNode *root);
void push(sNode **rootRef, int val);
int pop(sNode **rootRef);
void printStack(sNode *root);

int main(int argc, char **argv)
{
  sNode *root = newNode(1);
  sNode **rootRef = &root;
  printStack(root);
  push(rootRef, 2);
  printStack(root);
  push(rootRef, 3);
  printStack(root);
  pop(rootRef);
  printStack(root);
  pop(rootRef);
  printStack(root);
  pop(rootRef);
  printStack(root);
  
  return 0;
}

sNode *newNode(int val)
{
  sNode *stackNode = (sNode *)malloc(sizeof(sNode));
  stackNode->val = val;
  stackNode->next = NULL;
  return stackNode;
}

int isEmpty(sNode *root)
{
  return !root;
}

int peek(sNode *root)
{
  if(isEmpty(root))
    return 0;
  return root->val;
 }

void push(sNode **rootRef, int val)
{
  sNode *stackNode = newNode(val);
  stackNode->next = *rootRef;
  *rootRef = stackNode;
  printf("%d pushed to the stack\n", val);
 }

int pop(sNode **rootRef)
{
  if(isEmpty(*rootRef))
    return 0;
  sNode *temp = *rootRef;
  *rootRef = (*rootRef)->next;
  int popped = temp->val;
  free(temp);
  return popped;
}

void printStack(sNode *root)
{
  if(isEmpty(root)) {
    printf("Stack is empty\n");
    return;
  }
  sNode *curr = root;
  while(curr) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}
