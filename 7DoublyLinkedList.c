#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char ssn[50];
    char name[50];
    char dept[50];
    char desg[50];
    float sal;
    char phno[50];

    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE insert_front(char ssn[],char name[],char dept[],char desg[],float sal,char phno[],NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->ssn, ssn);
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    strcpy(temp->phno, phno);
    temp->rlink = temp->llink = NULL;

    if(first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;

    return first;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nThe list is empty:");
        return first;
    }

    if(first->rlink == NULL)
    {
        printf("\nThe following employee details are deleted:\n");
        printf("ssn:%s\n", first->ssn);
        printf("name:%s\n", first->name);
        printf("dept:%s\n", first->dept);
        printf("desg:%s\n", first->desg);
        printf("sal:%f\n", first->sal);
        printf("phno:%s\n", first->phno);
        free(first);
        return (NULL);
    }

    temp = first;
    first = first->rlink;
        printf("\nThe following employee details are deleted:\n");
        printf("ssn:%s\n", temp->ssn);
        printf("name:%s\n", temp->name);
        printf("dept:%s\n", temp->dept);
        printf("desg:%s\n", temp->desg);
        printf("sal:%f\n", temp->sal);
        printf("phno:%s\n", temp->phno);

    free(temp);
    first->llink = NULL;

    return first;
}

NODE insert_rear(char ssn[],char name[],char dept[],char desg[],float sal,char phno[],NODE first)
{
    NODE temp,cur;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->ssn, ssn);
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    strcpy(temp->phno, phno);
    temp->rlink = temp->llink = NULL;

    if(first == NULL)
        return temp;

    cur = first;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }

    cur->rlink = temp;
    temp->llink = cur;

    return first;
}

NODE delete_rear(NODE first)
{
    NODE prev,cur;
    if(first == NULL)
    {
        printf("\nThe list is empty:");
        return first;
    }

    if(first->rlink == NULL)
    {
        printf("\nThe following employee details are deleted:\n");
        printf("ssn:%s\n", first->ssn);
        printf("name:%s\n", first->name);
        printf("dept:%s\n", first->dept);
        printf("desg:%s\n", first->desg);
        printf("sal:%f\n", first->sal);
        printf("phno:%s\n", first->phno);
        free(first);
        return (NULL);
    }

    cur = first;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }

        printf("\nThe following employee details are deleted:\n");
        printf("ssn:%s\n", cur->ssn);
        printf("name:%s\n", cur->name);
        printf("dept:%s\n", cur->dept);
        printf("desg:%s\n", cur->desg);
        printf("sal:%f\n", cur->sal);
        printf("phno:%s\n", cur->phno);

        prev = cur->llink;
        free(cur);
        prev->rlink = NULL;

        return first;
}

void display(NODE first)
{
    NODE cur;
    int count = 0;
    if(first == NULL)
    {
        printf("\nThe list is empty:");
        printf("\nThe total number of nodes in the list is: %d\n", count);
        return;
    }

    printf("\nThe employee details are: \n");

    cur = first;
    while(cur != NULL)
    {
        count = count + 1;

        printf("ssn: %s\t", cur->ssn);
        printf("name: %s\t", cur->name);
        printf("dept: %s\t", cur->dept);
        printf("desg: %s\t", cur->desg);
        printf("sal: %f\t", cur->sal);
        printf("phno: %s\n", cur->phno);

        cur = cur->rlink;
    }

    printf("\nThe total number of nodes in the list is: %d\n", count);
}

void main()
{
    int choice,n,i;
    char ssn[50],name[50],dept[50],desg[50],phno[50];
    float sal;

    NODE first = NULL;

    printf("\nEnter the number of students:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter ssn:");
        scanf("%s", ssn);
        printf("\nEnter name:");
        scanf("%s", name);
        printf("\nEnter dept:");
        scanf("%s", dept);
        printf("\nEnter desg:");
        scanf("%s", desg);
        printf("\nEnter sal:");
        scanf("%f", &sal);
        printf("\nEnter phno:");
        scanf("%s", phno);

        first = insert_rear(ssn, name, dept, desg, sal, phno, first);
    }

    for(;;)
    {
        printf("\n1.INSERT FRONT\n2.DELETE FRONT");
        printf("\n3.INSERT REAR\n4.DELETE REAR");
        printf("\n5.DISPLAY\n6.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                    printf("\nEnter ssn:");
                    scanf("%s", ssn);
                    printf("\nEnter name:");
                    scanf("%s", name);
                    printf("\nEnter dept:");
                    scanf("%s", dept);
                    printf("\nEnter desg:");
                    scanf("%s", desg);
                    printf("\nEnter sal:");
                    scanf("%f", &sal);
                    printf("\nEnter phno:");
                    scanf("%s", phno);

                    first = insert_front(ssn, name, dept, desg, sal, phno, first);

                    break;

            case 2 :
                    first = delete_front(first);
                    break;

            case 3 :
                    printf("\nEnter ssn:");
                    scanf("%s", ssn);
                    printf("\nEnter name:");
                    scanf("%s", name);
                    printf("\nEnter dept:");
                    scanf("%s", dept);
                    printf("\nEnter desg:");
                    scanf("%s", desg);
                    printf("\nEnter sal:");
                    scanf("%f", &sal);
                    printf("\nEnter phno:");
                    scanf("%s", phno);

                    first = insert_rear(ssn, name, dept, desg, sal, phno, first);

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