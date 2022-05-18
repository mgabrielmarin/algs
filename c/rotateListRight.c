/*

Here we go again :D

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node *createNode(int val);
void addNodeToTail(Node *head, int val);
void printList(Node *head);
Node *rotateRight(Node *head, int totalRot);

int main(int argc, char **argv)
{
  Node *head = createNode(0);
  printList(head);
  addNodeToTail(head, 1);
  addNodeToTail(head, 2);
  printList(head);
  Node *newHead = rotateRight(head, 4);
  printList(newHead);
  
  return 0;
}

Node *createNode(int val)
{
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

void addNodeToTail(Node* head, int val)
{
  Node *curr = head;
  Node *newNode = createNode(val);
  while(curr->next) {
    curr = curr->next;
  }
  curr->next = newNode;
}

void printList(Node *head)
{
  Node *curr = head;
  while(curr->next) {
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("%d\n", curr->val);
}

Node *rotateRight(Node *head, int totalRot)
{
  if(head == NULL) return head;
  Node *curr = head;
  int lastNodeIndex = 0, totalNodes = 0;
  while(curr->next) {
    totalNodes += 1;
    curr = curr->next;
  }
  curr->next = head; // link list in a cyrcle
  lastNodeIndex = totalNodes - (totalRot % (totalNodes + 1));
  while(lastNodeIndex) {
    head = head->next;
    lastNodeIndex -= 1;
  }
  curr = head;
  head = head->next;
  curr->next = NULL;
  return head;
}








