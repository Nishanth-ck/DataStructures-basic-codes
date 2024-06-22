#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void push(int item,int *top,int s[])
{
    if(*top == MAX-1)
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
    *top = *top - 1;
    return (item);
}

void display(int top,int s[])
{
    int i;
    if(top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nThe contents of the stack are\n");

    for(i=0;i<=top;i++)
    {
        printf("%d\n", s[i]);
    }
}

void main()
{
    int s[MAX], item, choice, y, top;
    top = -1;

    for (;;)
    {
        printf("\n1.PUSH    2.POP   3.DISPLAY   4.EXIT\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 :
                    printf("\nEnter the item\n");
                    scanf("%d",&item);
                    push(item,&top,s);
                    break;

            case 2 :
                    y = pop(&top,s);
                    if(y==-1)
                    {
                        printf("\nStack Underflow\n");
                    }
                    else
                    {
                        printf("\nThe item popped is : %d\n", y);
                    }
                    break;

            case 3 :
                display(top, s);
                break;

            case 4 :
                exit(0);
        }
    }
}




