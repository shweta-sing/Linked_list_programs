#include<stdio.h>
#include <malloc.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
} list;
list *start = NULL;



int insert_end(int num)
{
    list *current;
    list *node = (list*)malloc(sizeof(list));
    node->next = NULL;
    node->data = num;
    if(start==NULL)
        start = node;

    else{
        if(start->next==NULL)
            start->next = node;
        else{
            current = start;
            while(current->next!= NULL)
                current = current->next;
            current->next = node;
        }
    }
    printf("\nValue inserted successfully.\n");
    return 1;
}


int print_list()
{
    list *current;
    if(start==NULL)
        printf("\nList is empty. Nothing to display.");
    else
    {
        current = start;
        printf("\n[ ");
        while(current -> next!= NULL)
        {
            printf("%d, ",current->data);
            current = current->next;
        }
        printf("%d ]\n", current->data);
    }
}

int list_rotation(int num)
{
    list *current=NULL, *target=NULL, *head;
    int is_rotate=0;
    if(start!=NULL)
    {
        if(start->next == NULL)
        {
            if(start->data==num)
            {
                is_rotate = 1;
                printf("\nThe original list was: \n");
                print_list();
            }
            else
                is_rotate = -1;
        }

        else
        {
            current = start;
            while(1)
            {
                if(current->data == num)
                {
                    is_rotate = 1;
                    break;
                }

                if(current->next!=NULL)
                    current = current->next;
                else
                {
                    if(current->data == num)
                        is_rotate = 1;
                    break;
                }
            }

            if(is_rotate==1&&start->next!=NULL)
            {
                printf("\nThe original list was: \n");
                print_list();
                if(current==start)
                    is_rotate = 1;
                else
                {
                    head = current;
                    current = start;
                    while(current->next!=head)
                        current = current->next;
                    current->next = NULL;
                    current = head;
                    while(current->next!=NULL)
                        current = current->next;
                    current->next = start;
                    start = head;
                    is_rotate = 1;
                }
            }
        }
    }
    if(is_rotate==1)
    {
        printf("\nThe rotated list is: \n");
        print_list();
        return 1;
    }
    else
        return -1;
}

int main()
{
    int choice, num, output;
    while(choice!=4)
    {
        printf("\n\n1. Insert element at the end\t2. Print the list\t3. Rotation\t4.EXIT");
        printf("\nChoose an option from the menu: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter value: ");
                scanf("%d",&num);
                insert_end(num);
                break;
            case 2:
                print_list();
                break;
            case 3:
                if(start!=NULL)
                {
                    print_list();
                    printf("\nThis is the list. Choose the number by which an clockwise rotation will be performed: ");
                    scanf("%d", &num);
                    output = list_rotation(num);
                    if(output==1)
                        printf("\nRotation about %d is successful. ", num);
                    else
                        printf("\nEntered element is not present in the list. Enter a valid number.");
                }
                else
                    printf("\nThe list is empty. Enter elements before performing this operation.");
                break;
            case 4:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}