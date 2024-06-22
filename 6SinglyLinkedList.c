#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char usn[50];
    char name[50];
    char branch[50];
    int sem;
    char phno[50];
    struct node *link;
};

typedef struct node * NODE;

NODE insert_front(char usn[],char name[],char branch[],int sem,char phno[],NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));

    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem=sem;
    strcpy(temp->phno, phno);

    temp->link = first;

    return temp;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nList is empty\n");
        return first;
    }

    temp = first;
    first = first->link;

    printf("\nThe Student with following details is deleted\n");
    printf("usn: %s\n", temp->usn);
    printf("name: %s\n", temp->name);
    printf("branch: %s\n", temp->branch);
    printf("sem: %d\n", temp->sem);
    printf("phno: %s\n", temp->phno);

    free(temp);

    return first;
}

NODE insert_rear(char usn[],char name[],char branch[],int sem,char phno[],NODE first)
{
    NODE temp,cur;
    temp = (NODE)malloc(sizeof(struct node));

    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem=sem;
    strcpy(temp->phno, phno);

    temp->link = NULL;

    if(first == NULL)
    {
        return temp;
    }

   cur = first;
   while(cur->link != NULL)
   {
       cur = cur->link;
   }

   cur->link = temp;

   return first;
}

NODE delete_rear(NODE first)
{
    NODE prev,cur;
    if(first == NULL)
    {
        printf("\nList is empty\n");
        return first;
    }

    if(first->link == NULL)
    {
        printf("\nThe Student with following details is deleted\n");
        printf("usn: %s\n", first->usn);
        printf("name: %s\n", first->name);
        printf("branch: %s\n", first->branch);
        printf("sem: %d\n", first->sem);
        printf("phno: %s\n", first->phno);
        free(first);
        return (NULL);
    }

    prev = NULL;
    cur = first;

    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    
    printf("\nThe Student with following details is deleted\n");
    printf("usn: %s\n", cur->usn);
    printf("name: %s\n", cur->name);
    printf("branch: %s\n", cur->branch);
    printf("sem: %d\n", cur->sem);
    printf("phno: %s\n", cur->phno);

    free(cur);

    prev->link = NULL;

    return first;
}

void display(NODE first)
{
    NODE cur;
    int count = 0;

    if(first == NULL)
    {
        printf("\nThe list is empty\n");
        printf("\nThe number of node in the list is: %d\n", count);
        return ;
    }

    cur = first;
    printf("\nThe contents of the list are:\n ");
    
    while(cur != NULL)
    {
        count = count + 1;

        printf("usn: %s\t", cur->usn);
        printf("name: %s\t", cur->name);
        printf("branch: %s\t", cur->branch);
        printf("sem: %d\t", cur->sem);
        printf("phno: %s\n", cur->phno);

        cur = cur->link;
    }

    printf("\nThe number of node in the list is: %d\n", count);
}

void main()
{
    int choice,sem,n,i;
    char usn[50], name[50], branch[50], phno[50];

    NODE first = NULL;

    printf("\nEnter the number of students:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter usn:");
        scanf("%s", usn);
        printf("\nEnter name:");
        scanf("%s", name);
        printf("\nEnter branch:");
        scanf("%s", branch);
        printf("\nEnter sem:");
        scanf("%d", &sem);
        printf("\nEnter phno:");
        scanf("%s", phno);

        first = insert_front(usn, name, branch, sem, phno, first);
    }

    for(;;)
    {
        printf("\n1.INSERT FRONT\n2.DELETE FRONT");
        printf("\n3.INSERT REAR\n4.DELETE REAR");
        printf("\n5.DISPLAY\n6.EXIT\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 :
                    printf("\nEnter usn:");
                    scanf("%s", usn);
                    printf("\nEnter name:");
                    scanf("%s", name);
                    printf("\nEnter branch:");
                    scanf("%s", branch);
                    printf("\nEnter sem:");
                    scanf("%d",&sem);
                    printf("\nEnter phno:");
                    scanf("%s", phno);

                    first = insert_front(usn,name,branch,sem,phno,first);

                    break;

            case 2 :
                    first = delete_front(first);
                    break;

            case 3 :
                    printf("\nEnter usn:");
                    scanf("%s", usn);
                    printf("\nEnter name:");
                    scanf("%s", name);
                    printf("\nEnter branch:");
                    scanf("%s", branch);
                    printf("\nEnter sem:");
                    scanf("%d", &sem);
                    printf("\nEnter phno:");
                    scanf("%s", phno);

                    first = insert_rear(usn,name,branch,sem,phno,first);

                    break;

            case 4 :
                    first = delete_rear(first);
                    break;

            case 5 :
                    display(first);
                    break;

            case 6 :
                exit(0);
        }
    }
}

