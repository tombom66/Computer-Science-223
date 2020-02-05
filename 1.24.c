#include <stdio.h>
#include <stdlib.h>
#define INITIALSTACK 8
#define FALSE 0
#define TRUE 1 f
typedef struct {
  int position;
  int maxLength;
  char *array;
} stack;
int match(char, char);
create();
void delete (stack *);
push(stack *, char);
pop(stack *);
int main(int argc, char *argv[]) {
  FILE *fptr;
  fptr = fopen(argv[0], "r");
  char c, out;
  elemStack = create();
  inComment, startComment, i, lineNum;
  int returnValue;
  escaped = inString = inChar = inComment = startComment = 0;
  lineNum = 1;
  while ((c = getc(fptr)) != EOF) {
    if (c == '\n')
      lineNum++;
    if (escaped) {
      escaped = FALSE;
    } else if (c == '\\') {
      escaped = TRUE;
    } else if (inString) {
      if (c == '"' && !escaped) {
        inString = FALSE;
      }
    } else if (inChar) {
      if (escaped)
        escaped = FALSE;
      else if (c == '\'' && !escaped) {
        inChar = FALSE;
      }
    } else if (inComment) {
      if (c == '*')
        startComment = TRUE;
      else if (c == '/' && startComment)
        inComment = FALSE;
      else
        startComment = FALSE;
    } else if (c == '*' && startComment)
      inComment = TRUE;
    else if (c == '/')
      startComment = TRUE;
    else if (c == '"') {
      inString = TRUE;
    } else if (c == '\'') {
      inChar = TRUE;
    } /* Accept the
character and check braces on the stack */
    else {
      startComment = FALSE;
      if (c == '(' || c == '[' || c == '{')
        push(&elemStack, c);
      else if (c == ')' || c == ']' || c == '}') {
        out = pop(&elemStack);
        if (out == -1 || !match(out, c)) {
          printf("Syntax error on line %d: %c matched with %c\n.", lineNum, out,
                 c);
          return -1;
        }
      }
    }
  }
  if (inString || inChar) {
    printf("Syntax error: Quote not terminated by end of file.\n");
    returnValue = -1;
  } else if (!elemStack.position) { printf("Syntax check
   passed on %d line(s).\n", lineNum); returnValue = 0; } else {
   printf("Syntax error: Reached end of file with %d unmatched elements.\n ",
   elemStack.position); for(i = 0; i < elemStack.position; ++i) printf(" %c",
   elemStack.array[i]); printf("\n"); returnValue = -1;
  }
  delete (&elemStack);
  return returnValue;
}
int match(char left, char right) {
  return ((left == '{' && right == '}') || (left == '(' && right == ')') ||
          (left == '[' && right == ']'));
} // checks for matching of brackets stack create() { stack
newStack;
newStack.array = malloc(INITIALSTACK * sizeof(char));
newStack.maxLength = INITIALSTACK;
newStack.position = 0;
return newStack;
} // creation of stack of size 8 and INITIALSTACK has already been
predefined above.This
    function returns a Stack of size 8. void delete (stack *stack) {
  free(stack->array);
  stack->array = NULL;
}
void push(stack *stack, char elem) {
  if (stack->position >= stack->maxLength) {
    char *newArray = malloc(2 * (stack->maxLength) * sizeof(char));
    int i;
    for (i = 0; i < stack->maxLength; ++i)
      newArray[i] = stack->array[i];
    free(stack->array);
    stack->array = newArray;
  }
  stack->array[stack->position] = elem;
  (stack->position)++;
}
char pop(stack *stack) {
  if (!(stack->position)) { printf("Pop attempted on
   empty stack.\n"); return -1; } else { (stack -> position)--; return stack
   -> array[stack -> position];
  }
}
