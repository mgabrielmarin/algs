/*



 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// TreeNode Stack implementation
typedef struct StackNode {
  struct TreeNode *tNode;
  struct StackNode *sNode;
} StackNode;

// Stack functions
StackNode *createStackNode(TreeNode *tNode);
void push(StackNode **topRef, TreeNode *tNode);
TreeNode *pop(StackNode **topRef);
bool isEmpty(StackNode *top);

// Int Stack implementation
void printStack(int *arrTrav, int len);

// Tree functions 
TreeNode *createTreeNode(int val);
void printTreePreOrder(TreeNode *root);
void printTreeInOrder(TreeNode *root);
void printTreePostOrder(TreeNode *root);
int nodeCount(TreeNode *root);
// recursive versions
void preOrder(TreeNode *root, int *res, int *size);
int *preOrderTraversal(TreeNode *root, int *retSize);
void inOrder(TreeNode *root, int *res, int *size);
int *inOrderTraversal(TreeNode *root, int *retSize);
void postOrder(TreeNode *root, int *res, int *size);
int *postOrderTraversal(TreeNode *root, int *retSize);

// iterative using stack
void preOrderStack(TreeNode *root, int *res, int *size);
int *preOrderStackTraversal(TreeNode *root, int *retSize);
void inOrderStack(TreeNode *root, int *res, int *size);
int *inOrderStackTraversal(TreeNode *root, int *retSize);
void postOrderStack(TreeNode *root, int *res, int *size);
int *postOrderStackTraversal(TreeNode *root, int *retSize);

void inOrderStackTraversalPrint(TreeNode *root, int *retSize);

// iterative without stack Morris Traversal

int main(int argc, char **argv)
{
  TreeNode *root = createTreeNode(1);
  root->left = createTreeNode(2);
  root->right = createTreeNode(3);
  printf("Print tree in different orders\n");
  printTreePreOrder(root);
  printTreeInOrder(root);
  printTreePostOrder(root);
  printf("\n");
  printf("The number of nodes in tree is %d\n", nodeCount(root));
  // Traversals
  int len = nodeCount(root);
  int *arrTrav; 
  int *retSize = (int *)malloc(sizeof(int));
  // Recursive
  printf("Recursive\n");
  // preOrder
  arrTrav = preOrderTraversal(root, retSize);
  printf("preOrder: ");
  printStack(arrTrav, len);
 // inOrder
  arrTrav = inOrderTraversal(root, retSize);
  printf("inOrder: ");
  printStack(arrTrav, len);
  // postOrder
  arrTrav = postOrderTraversal(root, retSize);
  printf("postOrder: ");
  printStack(arrTrav, len);
  // Iterative with stack
  printf("Iterative\n");
  // inOrder
  arrTrav = inOrderStackTraversal(root, retSize);
  printf("inOrderStack: ");
  printStack(arrTrav, len);
 
  return 0;
}

// TreeNode Stack functions implementation
StackNode *createStackNode(TreeNode *tNode)
{
  StackNode *newStackNode = (StackNode *)malloc(sizeof(StackNode));
  newStackNode->tNode = tNode;
  newStackNode->sNode = NULL;
  return newStackNode;
}

void push(StackNode **topRef, TreeNode *tNode)
{
  StackNode *stackNode = createStackNode(tNode);
  stackNode->sNode = *topRef;
  *topRef = stackNode;
}

TreeNode *pop(StackNode **topRef)
{
  if(*topRef == NULL) return NULL;
  StackNode *temp = *topRef;
  *topRef = (*topRef)->sNode;
  TreeNode *popped = temp->tNode;
  free(temp);
  return popped;
}

bool isEmpty(StackNode *top)
{
  return (top == NULL) ? 1 : 0;
}

// Int stack functions implementation

void printStack(int *arrTrav, int len)
{
  for(int i = 0; i < len; i += 1)
    printf("%d ", arrTrav[i]);
  printf("\n");
}

// Tree functions implementation
TreeNode *createTreeNode(int val)
{
  TreeNode *newTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
  newTreeNode->val = val;
  newTreeNode->left = NULL;
  newTreeNode->right = NULL;
  return newTreeNode;
}

void printTreePreOrder(TreeNode *root)
{
  if(root == NULL) return;
  printf("%d ", root->val);
  printTreeInOrder(root->left);
  printTreeInOrder(root->right);
}

void printTreeInOrder(TreeNode *root)
{
  if(root == NULL) return;
  printTreeInOrder(root->left);
  printf("%d ", root->val);
  printTreeInOrder(root->right);
}

void printTreePostOrder(TreeNode *root)
{
  if(root == NULL) return;
  printTreeInOrder(root->left);
  printTreeInOrder(root->right);
  printf("%d ", root->val);
}

int nodeCount(TreeNode *root)
{
  if(root == NULL) return 0;
  return nodeCount(root->left) + nodeCount(root->right) + 1;
}

void preOrder(TreeNode *root, int *res, int *size)
{
  if (root == NULL) return;
  res[(*size)++] = root->val;
  preOrder(root->left, res, size);
  preOrder(root->right, res, size);
}

int *preOrderTraversal(TreeNode *root, int *retSize)
{
  int len = nodeCount(root);
  int *result = (int *)malloc(sizeof(int)*len+1);
  *retSize = 0;
  preOrder(root, result, retSize);
  return result;
}

void inOrder(TreeNode *root, int *res, int *size)
{
  if (root == NULL) return;
  inOrder(root->left, res, size);
  res[(*size)++] = root->val;
  inOrder(root->right, res, size);
}

int *inOrderTraversal(TreeNode *root, int *retSize)
{
  int len = nodeCount(root);
  int *result = (int *)malloc(sizeof(int)*len+1);
  *retSize = 0;
  inOrder(root, result, retSize);
  return result;
}

void postOrder(TreeNode *root, int *res, int *size)
{
  if (root == NULL) return;
  postOrder(root->left, res, size);
  postOrder(root->right, res, size);
  res[(*size)++] = root->val;
}

int *postOrderTraversal(TreeNode *root, int *retSize)
{
  int len = nodeCount(root);
  int *result = (int *)malloc(sizeof(int)*len+1);
  *retSize = 0;
  postOrder(root, result, retSize);
  return result;
}

// Iterative approach

void preOrderStack(TreeNode *root, int *res, int *size)
{
  TreeNode *curr = root;
  StackNode *stack = NULL;
  bool done = 0;
  
  while(!done) {
    if(curr != NULL) {
      push(&stack, curr);
      curr = curr->left;
    } else {
      if(!isEmpty(stack)) {
        curr = pop(&stack);
        res[(*size)++] = curr->val;  
      } else {
        done = 1;
      }
    }
  }
}

int *preOrderStackTraversal(TreeNode *root, int *retSize)
{
  int len = nodeCount(root);
  int *result = (int *)malloc(sizeof(int)*len+1);
  *retSize = 0;
  preOrder(root, result, retSize);
  return result;
}

void inOrderStack(TreeNode *root, int *res, int *size)
{
  TreeNode *curr = root;
  StackNode *stack = NULL; 
  bool done = 0;
  
  while(!done) {
    if(curr != NULL) {
      push(&stack, curr);
      curr = curr->left;
    } else {
      if(!isEmpty(stack)) {
        curr = pop(&stack);
        res[(*size)++] = curr->val;  
        curr = curr->right;
      } else {
        done = 1;
      }
    }
  }
}

int *inOrderStackTraversal(TreeNode *root, int *retSize)
{
  int len = nodeCount(root);
  int *result = (int *)malloc(sizeof(int)*len+1);
  *retSize = 0;
  inOrderStack(root, result, retSize);
  return result;
}

