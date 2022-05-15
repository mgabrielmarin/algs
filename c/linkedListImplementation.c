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
void deleteLinkedListNthElemAtEnd(node *head, int n);
void deleteLinkedList(node *head); // delete all the nodes
bool hasCycle(node *head); // detect if linked list has cycle
node *detectCycle(node *head); // return cycle first node else return NULL;
node *reverseLinkedList(node *head);
void oddEvenIndexesSortList(node *head);
bool isPalindrome(node *head);
node *mergeTwoLinkedLists(node *list1, node *list2);
node *addTwoNumbers(node *list1, node *list2);

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
  printf("%d\n", isPalindrome(head));
  oddEvenIndexesSortList(head);
  printLinkedList(head);
  printf("Sorted odd indexes from even...\n");
  node *newHead = reverseLinkedList(head);
  printLinkedList(newHead);
  printf("Reversed...\n");
  deleteLinkedListAtIndex(newHead, 3);
  printLinkedList(newHead);
  deleteLinkedListNthElemAtEnd(newHead, 1);
  printLinkedList(newHead);
  deleteLinkedList(newHead);
  printLinkedList(newHead);
  printf("%d\n",hasCycle(newHead));

  // Merge and add two linked List testing
  node *head1 = createNode(1);
  node *head2 = createNode(2);
  
  addLinkedListTail(head1, 3);
  addLinkedListTail(head1, 5);
  addLinkedListTail(head2, 4);
  addLinkedListTail(head2, 6);
  printf("Two linked Lists\n");
  printLinkedList(head1);
  printLinkedList(head2);

  printf("Linked List after adding\n");
  node *headSumLists = addTwoNumbers(head1, head2);
  printLinkedList(headSumLists);

  printf("Linked List after merging\n");
  node *headMergedLists = mergeTwoLinkedLists(head1, head2);
  printLinkedList(headMergedLists);
  
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
  while(iter && !hasCycle(head)) // print only if there is not a cycle
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

void deleteLinkedListNthElemAtEnd(node *head, int n)
{
  node *tmp, *tmp2, *iter;
  tmp = tmp2 = iter = head;
  for(int i = 0; i < n; i += 1)
    iter = iter->next;
  if(!iter) 
  {
    tmp = head;
    head = head->next; 
    free(tmp);
  }
  while(iter->next)
  {
    iter = iter->next;
    tmp = tmp->next;
  }
  tmp2 = tmp->next;
  tmp->next = tmp->next->next;
  free(tmp2);
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

node *detectCycle(node *head)
{
  // check if list has mininum 2 nodes
  if (head == NULL || head->next == NULL) return NULL;
  node *curr, *slow, *fast;
  curr = slow = fast = head;
  // check if we have a cycle
  while(fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) // if we have a cycle
    {
      while(slow != curr) // find where cycle starts
      {
        curr = curr->next;
        slow = slow->next;
      }
      return curr;
    }
  }
  return NULL;
}

node *reverseLinkedList(node *head)
{
  node *prev = NULL, *curr, *foll; 
  curr = foll = head;
  while(curr)
  {
    foll = foll->next;
    curr->next = prev;
    prev = curr;
    curr = foll;
  }
  return prev;
}

void oddEvenIndexesSortList(node *head)
{
  if (head == NULL) return;
  node *odd, *even, *evenHead;
  odd = head, even = evenHead = head->next; 
  while(even && even->next)
  {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
}

bool isPalindrome(node *head)
{
  if (head == NULL) return NULL;
  int maxStack = 0;
  node *iter = head;
  while(iter) // find linked list len
  {
    iter = iter->next;
    maxStack += 1;
  }
  iter = head;
  int stack[maxStack];
  for(int i = maxStack-1; i >= 0; i -= 1) // put elements in stack
  {
    stack[i] = iter->val;
    iter = iter->next;
  }
  iter = head;
  for(int i = 0; i < maxStack; i += 1)
  {
    if (stack[i] != iter->val) return false;
    iter = iter->next;
  }
  return true;
}

node *mergeTwoLinkedLists(node *list1, node *list2)
{
  if(list1 == NULL && list2 == NULL) return NULL;
  node head;
  node *headRef = &head;
  while(list1 && list2) {
    if(list1->val < list2->val) {
      headRef->next = list1;
      list1 = list1->next;
      headRef = headRef->next;
    } else {
      headRef->next = list2;
      list2 = list2->next;
      headRef = headRef->next;
    }
  }
  if(list1) {
    headRef->next = list1;
  }
    if(list2) {
    headRef->next = list2;
  }
  return head.next;
}

node *addTwoNumbers(node *list1, node *list2)
{
  node sumHead;
  node *sumHeadRef = &sumHead;
  int adder = 0;
  while(list1 || list2 || adder) {
    if(list1) {
      adder += list1->val;
      list1 = list1->next;
    }
    if(list2) {
      adder += list2->val;
      list2 = list2->next;
    }
    sumHeadRef = sumHeadRef->next = (node *)malloc(sizeof(node));
    sumHeadRef->val = adder % 10;
    adder = adder / 10;
  }
  sumHeadRef->next = NULL;
  
  return sumHead.next;
}
