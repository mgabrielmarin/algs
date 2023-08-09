/*

Written on Emacs..."The superior editor"..."They" say...
1. Copy all the nodes from the list and merge them 
1->2->3->NULL => 1->1->2->2->3->3->NULL
2. Iterate and copy random nodes from original nodes.
3. Unmerge the list, unlink it 

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
  struct Node *random;
} Node;

Node *createNode(int val);
Node *copyNode(Node *node);
Node *copyRandomList(Node *head);
void printList(Node *head);
void printListAddr(Node *head);
void addAtTail(Node *head, int val);

int main(int argc, char **argv)
{

  // Some testing
  Node *head = createNode(1);
  printList(head);
  addAtTail(head, 2);
  printList(head);
  printListAddr(head);

  // deep copy the list
  Node *copyHead = copyRandomList(head);
  printList(copyHead);
  printListAddr(copyHead);

  return 0;
}

Node *createNode(int val)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  newNode->random = NULL;
  return newNode;
}

Node *copyNode(Node *node)
{
  Node *newNode = createNode(node->val);
  return newNode;
}

Node *copyRandomList(Node *head)
{
  if(head == NULL) return NULL;
  Node *curr = head;
  Node *copyCurr = NULL;
  // double the list with linked deep copy nodes 
  while(curr) {
    copyCurr = copyNode(curr);
    Node *next = curr->next;
    curr->next = copyCurr;
    copyCurr->next = next;
    curr = next;
  }
  // Copy random pointer
  curr = head;
  while(curr) {
    if(curr->random) {
      curr->next->random = curr->random->next;
    } else {
      curr->next->random = NULL;
    }
    curr = curr->next->next;
  }
  // Unlink nodes
  curr = head;
  copyCurr = curr->next;
  Node *copyHead = curr->next;
  while(curr) {
    curr->next = curr->next->next;
    if(copyCurr->next) {
      copyCurr->next = copyCurr->next->next;
    }
    curr = curr->next;
    copyCurr = copyCurr->next;
  }
  
  return copyHead;
}

void printList(Node *head)
{
  if(head == NULL) return;
  Node *curr = head;
  while(curr->next) {
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("%d\n", curr->val);
}

void printListAddr(Node *head)
{
  Node *curr = head;
  while(curr->next) {
    printf("%p -> ", curr);
    curr = curr->next;
  }
  printf("%p\n", curr);
}

void addAtTail(Node *head, int val)
{
  if (head == NULL) return;
  Node *curr = head;
  Node *newNode = createNode(val);
  while(curr->next) {
    curr = curr->next;
  }
  curr->next = newNode;
}
