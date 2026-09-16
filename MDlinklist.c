#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *add;
};

struct node *start = NULL, *new1, *temp, *prev, *next;

void create();
void insertatfirst();
void insertatlast();
void insertatmiddle();
void display();
void deleteatfirst();
void deleteatlast();
void deleteatanyposition();
void deletebyvalue();

int main()
{
    int choice;
    do
    {
        printf("\n1.Create a linked list");
        printf("\n2`.Insert at first");
        printf("\n3.Insert at last");
        printf("\n4.Insert at middle");
        printf("\n5.Display the linked list");
        printf("\n6.Delete at first");
        printf("\n7.Delete at last");
        printf("\n8.Delete at any position");
        printf("\n9.Delete by value");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                insertatfirst();
                break;
            case 3:
                insertatlast();
                break;
            case 4:
                insertatmiddle();
                break;
            case 5:
                display();
                break;
            case 6:
                deleteatfirst();
                break;
            case 7: 
                 deleteatlast();
                 break;
            case 8:
                 deleteatanyposition();
                 break;
            case 9:
                 deletebyvalue();
                 break; 
            default:
                printf("\nInvalid choice");
        }
    }while(choice!=10);
    return 0;
}
void create()
{
    int n;
    char ch;

    printf("\nEnter an element: ");
    scanf("%d", &n);

    start = (struct node*)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;

    printf("\nDo you want to continue? (y/n): ");
    ch = getchar();

    while (ch == 'y' || ch == 'Y')
    {
        printf("\nEnter next element: ");
        scanf("%d", &n);

        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;

        temp->add = new1;
        temp = temp->add;

        printf("\nWant to continue? (y/n): ");
        ch = getche();
    }
}
void insertatfirst()
{
    int n;
    printf("\nEnter an element: ");
    scanf("%d", &n);

    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = n;
    new1->add = start;
    start = new1;
    printf("\nInserted at first.");
}

void insertatlast()
{
    int n;
    printf("\nEnter an element: ");
    scanf("%d", &n);

    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = n;
    new1->add = NULL;

    if (start == NULL)
    {
        start = new1;
        return;
    }

    temp = start;
    while (temp->add != NULL)
    {
        temp = temp->add;
    }
    temp->add = new1;
    printf("\nInserted at last.");
}

void insertatmiddle()
{
    int n, pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    printf("\nEnter an element: ");
    scanf("%d", &n);

    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = n;

    if (start == NULL || pos <= 1)
    {
        new1->add = start;
        start = new1;
        printf("\nInserted at first.");
        return;
    }

    temp = start;
    while (temp != NULL && i < pos)
    {
        prev = temp;
        temp = temp->add;
        i++;
    }

    if (temp == NULL)
    {
        prev->add = new1;
        new1->add = NULL;
        printf("\nInserted at end.");
        return;
    }

    new1->add = temp;
    prev->add = new1;
    printf("\nInserted in middle.");
}

void display()
{
    if (start == NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }

    printf("\nLinked list: ");
    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->add;
    }
}

void deleteatfirst()
{
    if (start == NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }

    temp = start;
    start = start->add;
    printf("\nDeleted element: %d", temp->data);
    free(temp);
}

void deleteatlast()
{
    if (start == NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }

    temp = start;
    prev = NULL;

    if (start->add == NULL)
    {
        printf("\nDeleted element: %d", start->data);
        free(start);
        start = NULL;
        return;
    }

    while (temp->add != NULL)
    {
        prev = temp;
        temp = temp->add;
    }

    printf("\nDeleted element: %d", temp->data);
    free(temp);
    prev->add = NULL;
}

void deleteatanyposition()
{
    int pos, i = 1;

    if (start == NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (pos <= 1)
    {
        deleteatfirst();
        return;
    }

    temp = start;
    prev = NULL;
    while (temp != NULL && i < pos)
    {
        prev = temp;
        temp = temp->add;
        i++;
    }

    if (temp == NULL)
    {
        printf("\nPosition not found.");
        return;
    }

    prev->add = temp->add;
    printf("\nDeleted element: %d", temp->data);
    free(temp);
}

void deletebyvalue()
{
    int value;
    if (start == NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &value);

    temp = start;
    prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->add;
    }

    if (temp == NULL)
    {
        printf("\nValue not found.");
        return;
    }

    if (prev == NULL)
    {
        start = temp->add;
    }
    else
    {
        prev->add = temp->add;
    }

    printf("\nDeleted element: %d", temp->data);
    free(temp);
}
