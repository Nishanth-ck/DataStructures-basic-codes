#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define stacksize 70

void push(int item,int *top,int s[])
{
    if(*top == stacksize-1)
    {
        printf("\nStack Overflow\n");
        return;
    }

    *top = *top+1;
    s[*top] = item;
}

int pop(int *top,int s[])
{
    int item;
    if(*top == -1)
    {
        return -1;
    }

    item = s[*top];
    *top = *top-1;
    return item;
}

int evaluate(char postfix[])
{
    int i, n, op1, op2, result, top, s[stacksize];
    char symbol;

    top = -1;
    n = strlen(postfix);

    for(i=0;i<n;i++)
    {
        symbol = postfix[i];

        switch(symbol)
        {
            case '+' :
                        op2 = pop(&top,s);
                        op1 = pop(&top, s);
                        result = op1 + op2;
                        push(result, &top, s);
                        break;

            case '-' :
                        op2 = pop(&top,s);
                        op1 = pop(&top, s);
                        result = op1 - op2;
                        push(result, &top, s);
                        break;

            case '/' :
                        op2 = pop(&top,s);
                        op1 = pop(&top, s);
                        result = op1 / op2;
                        push(result, &top, s);
                        break;

            case '*' :
                        op2 = pop(&top,s);
                        op1 = pop(&top, s);
                        result = op1 * op2;
                        push(result, &top, s);
                        break;

            case '^' :

            case '$' :
                        op2 = pop(&top,s);
                        op1 = pop(&top, s);
                        result = (int)pow((double)op1,(double)op2);
                        push(result, &top, s);
                        break;

            default :
                        push(symbol - '0', &top, s);
        }
    
    }

    return (pop(&top, s));
}

void main()
{
    int res;
    char postfix[50];

    printf("\nEnter the postfix expression:");
    scanf("%s", postfix);

    res = evaluate(postfix);

    printf("\nThe value of the postfix expression is : %d \n", res);
}