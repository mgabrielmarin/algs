/*

Trying a little bit of C++

 */

#include <iostream>

class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {
public:
  Node *flattenRec(Node *head) {
    Node *curr = head;
    while (curr) {
      if (curr->child) {
	Node *next = curr->next;
	Node *child = flattenRec(curr->child);
	curr->child = NULL;
	curr->next = child;
	child->prev = curr;
	while(curr->next) {
	  curr = curr->next;
	}
	curr->next = next;
	if(next) {
	  next->prev = curr;
	}
      }
      curr = curr->next;
    }
    return head;
  }
  
  Node *flattenIter(Node *head) {
    Node *curr = head;
    while(curr) {
      if(curr->child) {
	Node *next = curr->next;
	curr->next = curr->child;
	curr->next->prev = curr;
	curr->child = NULL;
	Node *tail = curr->next;
	while(tail->next) {
	  tail = tail->next;
	}
	tail->next = next;
	if(next) {
	  next->prev = tail;
	}
      }
      curr = curr->next;
    }

    return head;
  }
};

int main(int argc, char **argv)
{

  return 0;
}
