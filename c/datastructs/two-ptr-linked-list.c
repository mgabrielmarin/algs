/*

Framework from leetcode to solve to pointer problems 

*/

// Initialize slow & fast pointers

#include <stdio.h>
#include <stdlib.h> // for heap memory allocation...malloc
#include <stdbool.h> // for bool type vars...true, false

typedef struct node
{
  int val;
  struct node *next;
} node;

node *createNode(int val);

int main(int argc, char **argv)
{
  node *head = createNode(1);
  // Initialize slow & fast pointers 
  node *slow = head;
  node *fast = head;
  // Change this condition to fit specific problems
  // Attention to infamous null-pointer error.
  while (slow && fast && fast->next)
  {
    slow = slow->next; // move slow pointer one step
    fast = fast->next->next; // move fast pointer two steps
    if (slow == fast)
      return true;

  }
  return false; // change value to fit specific problem 
}

node *createNode(int val)
{
  node *new_node = malloc(sizeof(node));
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}
