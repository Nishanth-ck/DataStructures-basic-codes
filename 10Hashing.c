#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXADDR 100

struct employee
{
    int empid;
    int age;
    char name[20];
} ht[MAXADDR];

int hash(int key)
{
    int index;
    index = key % MAXADDR;
    return (index);
}

void main()
{
    int i, choice, count, key, age, index;
    char name[20];

    count = 0;

    for(i=0;i<MAXADDR;i++)
    {
        ht[i].empid = -1;
    }

    for (;;)
    {
        printf("\n1.INSERT RECORD       2.SEARCH RECORD     3.EXIT");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 :
                    if(count == MAXADDR)
                    {
                        printf("\nNO Space Available");
                    }
                    else
                    {
                        printf("\nEnter the 4-digit unique key for employee");
                        scanf("%d", &key);

                        printf("\nEnter the employee name");
                        scanf("%s",name);

                        printf("\nEnter the age");
                        scanf("%d", &age);

                        index = hash(key);

                        if(ht[index].empid == -1)
                        {
                            ht[index].empid = key;
                            strcpy(ht[index].name, name);
                            ht[index].age = age;
                            count = count + 1;
                            break;
                        }
                        else
                        {
                            for(i=1;i<MAXADDR;i++)
                            {
                                index = (hash(key) + i) % MAXADDR;

                                if(ht[index].empid == -1)
                                {
                                    ht[index].empid = key;
                                    strcpy(ht[index].name, name);
                                    ht[index].age = age;
                                    count = count + 1;
                                    break;
                                }
                            }
                        }
                    }

                    break;

            case 2 :
                    printf("\nEnter the 4-digit unique key for employee");
                    scanf("%d", &key);

                    index = hash(key);

                    if(ht[index].empid == key)
                    {
                        printf("\nSuccessful Search");
                        printf("Name = %s\n", ht[index].name);
                        printf("Age = %d\n", ht[index].age);
                        break;
                    }
                    else if(ht[index].empid == -1)
                    {
                        printf("\nUnsuccessful Search");
                        printf("\nKey not found");
                        break;
                    }
                    else
                    {
                        for (i = 1;i<MAXADDR;i++)
                        {
                            index = (hash(key) + i) % MAXADDR;

                            if(ht[index].empid == key)
                                {
                                    printf("\nSuccessful Search");
                                    printf("Name = %s\n", ht[index].name);
                                    printf("Age = %d\n", ht[index].age);
                                    break;
                                }

                            else if(ht[index].empid == -1)
                            {
                                printf("\nUnsuccessful Search");
                                printf("\nUnsuccessful Search");
                                printf("\nKey not found");
                                break;
                            }
                        }
                    }

                    printf("\nUnsuccessful Search");
                    printf("\nKey not found");
                    break;

            case 3 :
                exit(0);
        }
    }
}