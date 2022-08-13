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
    int i =1;
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


int reverse_list()
{
    list *current, *temp, *start2, *end;
    int flag=1; //to mark start of the reversed list
    if(start==NULL)
        return -1;
    else
    {
        if(start->next!=NULL)
        {
            while(start->next->next!=NULL)
            {
                current = start;
                while(current->next->next!=NULL)
                    current = current->next;
                list* node = (list*) malloc(sizeof (list));
                node-> data = current->next->data;
                node-> next = NULL;
                if(flag==1)
                {
                    start2 = node;
                    end = node;
                    flag++;
                }
                else
                {
                    end->next = node;
                    end = end->next;
                }
                free(current->next);
                current->next = NULL;
            }
            if(start->next->next==NULL)
            {
                if(flag==1)
                {
                    start2 = start->next;
                    start2->next = start;
                    start->next = NULL;
                    start = start2;
                }
                else
                {
                    end->next = start->next;
                    end = end->next;
                    end->next = start;
                    start->next = NULL;
                    start = start2;
                }
            }
        }
        return 1;
    }
}


/* Driver program to test above function*/
int main()
{
    int choice=0, num, output;
    while(choice !=4)
    {
        printf("\n\n1. Insert element at the end\t2. Print the list\t3. Reverse linked list\t4.EXIT");
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
                output = reverse_list();
                if(output==-1)
                    printf("\nList is empty. Add elements to the list before performing this operation. ");
                else
                {
                    printf("\nList reversed successfully. The reversed list is: ");
                    print_list();
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