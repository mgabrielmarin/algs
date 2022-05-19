/*



 */

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createTreeNode(int val);
void printTreePreOrder(TreeNode *root);
void printTreeInOrder(TreeNode *root);
void printTreePostOrder(TreeNode *root);
int nodeCount(TreeNode *root);
void preOrder(TreeNode *root, int *res, int *size);
int *preOrderTraversal(TreeNode *root, int *retSize);
void inOrder(TreeNode *root, int *res, int *size);
int *inOrderTraversal(TreeNode *root, int *retSize);
void postOrder(TreeNode *root, int *res, int *size);
int *postOrderTraversal(TreeNode *root, int *retSize);

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
  printf("Dynamic memory in the zone.\n");
  // preOrder
  arrTrav = preOrderTraversal(root, retSize);
  printf("preO.rder: ");
  for(int i = 0; i < len; i += 1)
    printf("%d ", arrTrav[i]);
  printf("\n");
 // inOrder
  arrTrav = inOrderTraversal(root, retSize);
  printf("inOrder: ");
  for(int i = 0; i < len; i += 1)
    printf("%d ", arrTrav[i]);
  printf("\n");
  // postOrder
  arrTrav = postOrderTraversal(root, retSize);
  printf("postOrder: ");
  for(int i = 0; i < len; i += 1)
    printf("%d ", arrTrav[i]);
  printf("\n");
 
  return 0;
}

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
