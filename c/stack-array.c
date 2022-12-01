/*

Basic stack implementations using arrays

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
  int top;
  unsigned capacity;
  int *array;
} Stack;

Stack *createStack(unsigned capacity);
void push(Stack *stack, int item);
int pop(Stack *stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void printStack(Stack *stack);
  

int main(int argc, char **argv)
{
  Stack *newStack = createStack(5);
  printStack(newStack);
  push(newStack, 1);
  printStack(newStack);
  push(newStack, 2);
  printStack(newStack);
  push(newStack, 3);
  printStack(newStack);
  pop(newStack);
  printStack(newStack);
  pop(newStack);
  printStack(newStack);
 
  return 0;
}

Stack *createStack(unsigned capacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(stack->capacity * sizeof(int));
  return stack;
}

void push(Stack *stack, int item)
{
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
  printf("%d pushed to the stack\n", item);
}

int pop(Stack *stack)
{
  if (isEmpty(stack))
    return 0;
  return stack->array[stack->top--];
}

int isFull(Stack *stack)
{
  return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
  return stack->top == -1;
}
  
void printStack(Stack *stack)
{
  if(isEmpty(stack)) {
    printf("Stack is empty\n");
    return;
  }
  if(isFull(stack)) {
    printf("Stack is full\n");
    return;
  }
  int top = stack->top;
  while(top >= 0) {
    printf("%d ", stack->array[top]);
    top -= 1;
  }
  printf("\n");
}
