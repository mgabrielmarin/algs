/*
 * Binary tree implementation
 */
#include <stdio.h>
#include <stdlib.h>

/* Structure represeting a node inside a binary tree */
struct node {
    int val;
    struct node *left;
    struct node *right;
};

/* Create a new node with values 'val' */
struct node *new_node(int val) {
    struct node *node = malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Recursive version to insert a node inside a binary tree */
struct node *insert_node(struct node *root, int val) {
    if (root == NULL)
        return new_node(val);
    if (val < root->val)
        root->left= insert_node(root->left, val);
    else if (val > root->val)
        root->right = insert_node(root->right, val);
    return root;
}

/* Recursive function that prints sorted values from binary tree */
void print_sorted(struct node *root) {
    if (root == NULL) return;
    print_sorted(root->left);
    printf("%d\n", root->val);
    print_sorted(root->right);
}

/* Recursive version of function that frees binary tree */
void free_tree(struct node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/* Imperative version to insert a node inside a binary tree */
struct node *insert_node2(struct node *root, int val) {
    struct node *saved_root = root;
    struct node *new = new_node(val);

    if (root == NULL)
        return new;

    while(1) {
        if (root->val < val) {
            if (root->right == NULL) {
                root->right = new;
                return saved_root;
            }
            root = root->right;
        } else {
            if (root->left == NULL) {
                root->left = new;
                return saved_root;
            }
            root = root->left;
        }
    }
}

/* TODO: implement imperative functions for print and free */

int main(void) {
    struct node *root = new_node(10);

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 100);
    root = insert_node(root, 5);
    root = insert_node(root, 22);
    print_sorted(root);
    free_tree(root);

    root = new_node(10);
    root = insert_node2(root, 30);
    root = insert_node2(root, 20);
    root = insert_node2(root, 100);
    root = insert_node2(root, 5);
    root = insert_node2(root, 22);
    print_sorted(root);
    free_tree(root);

    return 0;
}
