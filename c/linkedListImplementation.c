/*

Practice...Shh please...

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
  struct node *next;
  int val;
} node;

node *getNode(node* head, int index); // get node from list at index-th; 
node *createNode(int val); // create a new node with intput val;
node *createLinkedList(); // create the first node form linked list;
void printLinkedList(node *head); // what it says...by me...hope so...
int getLinkedListNode(node *head, int index); // get node at index-th;
void addLinkedListHead(node *head, int val); // add node after head;
void addLinkedListTail(node *head, int val); // add node to tail;
void addLinkedListAtIndex(node *head, int val, int index); // after index
void deleteLinkedListAtIndex(node *head, int index);
void deleteLinkedList(node *head); // delete all the nodes
bool hasCycle(node *head); // check if linkedList has a cycle;

int main(int argc, char **argv)
{
  node *head = createNode(1);
  printLinkedList(head);
  addLinkedListHead(head, 3);
  printLinkedList(head);
  addLinkedListHead(head, 2);
  printLinkedList(head);
  addLinkedListTail(head, 5);
  printLinkedList(head);
  addLinkedListAtIndex(head, 4, 2); 
  printLinkedList(head);
  printf("%d\n",hasCycle(head));
  deleteLinkedListAtIndex(head, 3);
  printLinkedList(head);
  deleteLinkedList(head);
  printLinkedList(head);

  return 0;
}

node *getNode(node* head, int index)
{
  int i = 0;
  node *iter = head;
  while (i < index && iter)
  {
    i++;
    iter = iter->next;
  }
  return iter;
}

node *createNode(int val)
{
  node *new_node = malloc(sizeof(node));
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

node *createLinkedList()
{
  node *head = malloc(sizeof(node));
  head->next = NULL;
  return head;
}

void printLinkedList(node *head)
{
  node *iter = head;
  while(iter)
  {
    printf("%d -> ",iter->val);
    iter = iter->next;
  }
  printf("\n");
}

int getLinkedListNode(node *head, int index)
{
  node *iter = getNode(head->next, index);
  return iter ? iter->val : -1;
}

void addLinkedListHead(node *head, int val) // add node to the head;
{
  node *new_head = createNode(val);
  new_head->next = head->next;
  head->next = new_head;
}

void addLinkedListTail(node *head, int val)
{
  node *iter = head;
  while(iter->next)
  {
    iter = iter->next;
  }
  iter->next = createNode(val);
}
void addLinkedListAtIndex(node *head, int val, int index)
{
  node *iter = getNode(head, index);
  if(iter) 
  {
    node *new_node = createNode(val);
    new_node->next = iter->next;
    iter->next = new_node;
  }
}

void deleteLinkedListAtIndex(node *head, int index)
{
  node *tmp, *iter = getNode(head, index);
  if(iter)
  {
    if(iter->next && iter->next->next)
    {
      tmp = iter->next;
      iter->next = iter->next->next;
      free(tmp);
    }
    else if(iter->next && iter->next->next == NULL)
    {
      tmp = iter->next;
      iter->next = NULL;
      free(tmp);
    }
  }
}

void deleteLinkedList(node *head)
{
  node *iter = head;
  
  while(iter->next)
  {
    node *tmp = iter->next;
    iter->next = iter->next->next;
    free(tmp);
  }
}

bool hasCycle(node *head)
{
  if(!head || !head->next)
    return false;
  node *slow = head->next, *fast = head->next->next;
  while (fast && fast->next)
  {
    if(slow == fast)
      return true;
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}
