#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {

    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}


char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}


int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter a valid infix expression: ");
    scanf("%s", exp);

    printf("\nPostfix expression: ");
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            // Operand → print directly
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')') {
            // Pop until '('
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            // Operator: pop higher or equal precedence
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }


    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}
