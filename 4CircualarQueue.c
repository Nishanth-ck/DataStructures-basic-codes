#include<stdio.h>
#include<stdlib.h>

#define queuesize 5

void insert_rear(int item,int *r,int *count,int q[])
{
    if(*count == queuesize)
    {
        printf("\nQueue Overflow");
        return;
    }

    *r = (*r + 1) % queuesize;
    q[*r] = item;
    *count = *count + 1;
}

void delete_front(int *f,int *count,int q[])
{
    int item;
    if(*count == 0)
    {
        printf("\nQueue is Empty\n");
        return;
    }

    item = q[*f];
    printf("\nThe item deleted is : %d", item);
    *f = (*f + 1) % queuesize;
    *count = *count - 1;
}

void display(int f,int count,int q[])
{
    int i;
    if(count == 0)
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("The contents of the circular queue are:\n");
    for (i = 1; i <= count;i++)
    {
        printf("%d\n",q[f]);
        f = (f + 1) % queuesize;
    }
}

void main()
{
    int f, r, choice, item, q[queuesize],count;
    f = 0;
    r = -1;
    count = 0;

    for (;;)
    {
        printf("\n1.INSERT REAR     2.DELETE FRONT      3.DISPLAY       4.EXIT\n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : 
                    printf("\nEnter the item:");
                    scanf("%d",&item);
                    insert_rear(item, &r, &count, q);
                    break;

            case 2 :
                    delete_front(&f, &count, q);
                    break;

            case 3 : 
                    display(f,count,q);
                    break;

            case 4 :
                exit(0);
        }
    }
}