#include<stdio.h>
#include <malloc.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
} list;
list *start = NULL;


/* Function to push a node */
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

/* Function to print linked list */
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


//Function to perform pair wise swapping of nodes
int pair_wise_swap()
{
    list *current=NULL, *node1=NULL, *node2=NULL, *previous=NULL;
    if(start!=NULL)
    {
        if(start->next!=NULL)
        {
            current = start;
            while(1)
            {
                if(current==start)
                {
                    node1 = current;
                    node2 = current->next;
                    node1->next = node2->next;
                    node2->next = node1;
                    current = current->next;
                    start = node2;
                }
                else
                {
                    previous = node1;//previous points to the node just before nodes to be swapped
                    //previous->node1->node2
                    node1 = current;
                    node2 = current->next;
                    node1->next = node2->next;
                    node2->next = node1;
                    previous->next = node2;
                    current = current->next;
                }
                if(current==NULL)
                    break;
                if(current->next==NULL)
                    break;
            }

            return 1;
        }
        else
            return -1;
    }
    else
        return -2;
}


/* Driver program to test above function*/
int main()
{
    int choice, num, output;
    while(choice!=4)
    {
        printf("\n\n1. Insert element at the end\t2. Print the list\t3. Pair wise swap\t4.EXIT");
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
                output = pair_wise_swap();
                if(output==-2)
                    printf("\nList is empty. Enter elements before performing this operation.");
                else
                {
                    if(output==-1)
                        printf("\nOnly one element is in the list. Add more elements to perform this operation");
                    else
                    {
                        printf("\nPair wise swapping is successful. Updated list is: ");
                        print_list();
                    }
                }
                break;
            case 4:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}