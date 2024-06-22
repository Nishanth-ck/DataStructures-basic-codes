#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node * NODE;

NODE insert_node(int item,NODE root)
{
    NODE cur, temp, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    if(root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while(cur != NULL)
    {
        prev = cur;
        if(item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if(item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

void inorder(NODE root)
{
    if(root == NULL)
        return;
    inorder(root->llink);
    printf("%d\t", root->info);
    inorder(root->rlink);
}

void preorder(NODE root)
{
    if(root == NULL)
        return;
    printf("%d\t", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if(root == NULL)
        return;
    preorder(root->llink);
    preorder(root->rlink);
    printf("%d\t", root->info);
}

NODE search(int item,NODE root)
{
    if(root == NULL || item == root->info)
    {
        return root;
    }

    if(item<root->info)
        return search(item,root->llink);

    return search(item, root->rlink);
}

void main()
{
    int choice, item;
    NODE root = NULL, temp;

    for (;;)
    {
        printf("\n1.Create");
        printf("\n2.Traverse the Tree in Preorder,Inorder,Postorder");
        printf("\n3.Search");
        printf("\n4.Exit");
        printf("\nEnter your choice");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 :
                printf("\nEnter the item to be inserted");
                scanf("%d", &item);
                root = insert_node(item,root);
                break;

            case 2 :
                    if(root == NULL)
                        printf("\nTree is not created");

                    else
                    {
                        printf("\nThe Inorder display:");
                        inorder(root);
                        printf("\nThe Preorder display:");
                        preorder(root);
                        printf("\nThe Postorder display:");
                        postorder(root);
                    }
                    break;

            case 3 :
                printf("\nEnter element to be searched");
                scanf("%d",&item);
                temp = search(item, root);
                if(temp == NULL)
                    printf("\nElement does not exist");
                else
                    printf("\nThe element %d is found", temp->info);

                break;

            case 4 :
                exit(0);
        }
    }
}
