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

/* Structure represeting a stack of nodes */
struct stack {
    struct node *topn;
    struct stack *next;
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

/* Check if stack is empty */
int is_empty(struct stack *top) {
    return (top == NULL) ? 1 : 0;
}

/* Push node to the stack */
void push(struct stack **topref, struct node *node) {
    struct stack *new = malloc(sizeof(struct stack));
    if (new == NULL) {
        perror("Out of memory\n");
        exit(1);
    }
    new->topn = node;
    new->next = *topref;
    *topref = new;
}

/* Pop node from the stack */
struct node *pop(struct stack **topref) {
    struct stack *top = *topref;
    struct node *pop = (*topref)->topn;
    *topref = (*topref)->next;
    free(top);
    return pop;
}

/* Peek node from the stack */
struct node *peek(struct stack *top) {
    if (is_empty(top)) return NULL;
    return top->topn;
}

/* Imperative function that prints sorted values from binary tree */
void print_sorted2(struct node *root) {
    struct node *curr = root;
    struct stack *top= NULL;

    while(curr != NULL || !is_empty(top)) {
        /* Go to the leftmost node and push all nodes
         * along the way to the stack */
        while(curr != NULL) {
            push(&top, curr);
            curr = curr->left;
        }
        /* Pop node print result then go to the right */
        curr = pop(&top);
        printf("%d\n", curr->val);
        curr = curr->right;
    }
}

/* Imperative version of function that frees binary tree */
void free_tree2(struct node *root) {
    struct node *curr = root;
    struct stack *top = NULL;
    struct node *lastn = NULL;

    while(curr != NULL || !is_empty(top)) {
        /* Go to the leftmost node and push all nodes
         * along the way to the stack */
        if (curr != NULL) {
            push(&top, curr);
            curr = curr->left;
        } else {
            /* Peek the top of the stack. If the right node
             * is not null and is different from the last freed
             * node, the current node becomes the right peeked node */
            struct node *peekn = peek(top);
            if (peekn->right != NULL && peekn->right != lastn) {
                curr = peekn->right;
            } else {
                pop(&top);
                free(peekn);
                lastn = peekn;
            }
        }
    }
}

int main(void) {
    struct node *root;

    /* Recursive functions */
    root = new_node(10);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 100);
    root = insert_node(root, 5);
    root = insert_node(root, 22);
    print_sorted(root);
    free_tree(root);

    /* Imperative functions */
    root = new_node(10);
    root = insert_node2(root, 30);
    root = insert_node2(root, 20);
    root = insert_node2(root, 100);
    root = insert_node2(root, 5);
    root = insert_node2(root, 22);
    print_sorted2(root);
    free_tree2(root);

    return 0;
}
