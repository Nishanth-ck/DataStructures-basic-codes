#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 70

int input_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':       return 1;
        case '*':
        case '/':
        case '%':       return 3;
        case '^':
        case '$':       return 6;
        case '(' :      return 9;
        case ')':       return 0;
        default :       return 7;

    }
}

int stack_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':       return 2;
        case '*':
        case '/':
        case '%':       return 4;
        case '^':
        case '$':       return 5;
        case '(' :      return 0;
        case '#':       return -1;
        default :       return 8;
        
    }
}

void push(char item,int *top,char s[])
{
    if(*top == MAX-1)
    {
        printf("Stack overflow");
        return;
    }

    *top = *top+1;
    s[*top] = item;
}

char pop(int *top,char s[])
{
    char item;
    if(*top == -1)
    {
        return -1;
    }

    item = s[*top];
    *top = *top - 1;
    return item;
}

void infix_postfix(char infix[],char postfix[])
{
    int n,i,j,top;
    char symbol,s[MAX];
    top = -1;
    j=0;

    push('#', &top, s);
    n = strlen(infix);
    for (i = 0;i<n;i++)
    {
        symbol = infix[i];

        while(stack_precedence(s[top]) > input_precedence(symbol))
        {
            postfix[j] = pop(&top, s);
            j = j + 1;
        }

        if(stack_precedence(s[top]) != input_precedence(symbol))
        {
            push(symbol, &top, s);
        }
        else
        {
            pop(&top, s);
        }
    }

    while(s[top] != '#')
    {
        postfix[j] = pop(&top, s);
        j = j + 1;
    }

    postfix[j] = '\0';
}

void main()
{
    char infix[70], postfix[70];

    printf("\nEnter the infix expression:");
    scanf("%s", infix);

    infix_postfix(infix, postfix);

    printf("\nThe postfix expression is: %s\n",postfix); 


}