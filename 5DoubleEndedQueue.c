#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void insert_rear(int item,int *r,int q[])
{
    if(*r == MAX - 1)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    *r = *r+1;
    q[*r] = item;
}

void insert_front(int item,int *f,int *r,int q[])
{
    if(*f==0 && *r!=-1)
    {
        printf("\nInsert Front NOT POSSIBLE\n");
        return;
    }

    if(*f==0)
    {
        *r = *r+1;
        q[*r] = item;
        return;
    }

    *f = *f-1;
    q[*f] = item;
}

void delete_front(int *f,int *r,int q[])
{
    int item;
    if(*f>*r)
    {
        printf("\nQueue is Empty\n");
        return;
    }

    item = q[*f];
    printf("\nThe item deleted at front end is: %d", item);
    *f = *f+1;

    if(*f>*r)
    {
        *f = 0;
        *r = -1;
    }
}

void delete_rear(int *f, int *r, int q[])
{
        int item;
        if(*f>*r)
    {
        printf("\nQueue is Empty\n");
        return;
    }

    item = q[*r];
    printf("\nThe item deleted at rear end is: %d", item);
    *r = *r-1;

    if(*f>*r)
    {
        *f = 0;
        *r = -1;
    }
}

    void display(int f, int r, int q[])
{
    int i;
    if(f>r)
    {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nThe contents of the queue are:\n");
    for(i=f;i<=r;i++)
    {
        printf("%d\n", q[i]);
    }
}

void main()
{
    int f,r,choice,item,q[MAX];
    f = 0;
    r = -1;

    for (;;)
    {
        printf("\n1.INSERT FRONT\n2.DELETE FRONT");
        printf("\n3.INSERT REAR\n4.DELETE REAR");
        printf("\n5.DISPLAY\n6.EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                    printf("\nEnter the item to insert at front end:");
                    scanf("%d", &item);
                    insert_front(item, &f, &r, q);
                    break;

            case 2 :
                    delete_front(&f,&r,q);
                    break;

            case 3 :
                    printf("\nEnter the item to insert at rear end:");
                    scanf("%d", &item);
                    insert_rear(item,&r, q);
                    break;

            case 4 :
                    delete_rear(&f,&r,q);
                    break;

            case 5 :
                    display(f,r,q);
                    break;

            case 6 :
                exit(0);
        }
    }
}



