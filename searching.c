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


int search_elt(int elt)
{
    list *current;
    int i =0;
    int elt_found=0;
    if(start==NULL)
        elt_found = -2;
    else
    {
        current = start;
        while(current!=NULL)
        {
            i++;
            if(current->data == elt)
            {
                elt_found++;
                break;
            }
            current = current->next;
        }
    }
    if(elt_found==1)
        return i;
    else
        return -1;
}

int search_by_pos(int pos)
{
    list *current;
    int i=0;
    if(start!=NULL)
    {
        current = start;
        i++;
        while(i<pos && current!=NULL)
        {
            current = current->next;
            i++;
        }

        if(current==NULL)
        {
            printf("\nPosition is greater than the number of elements in the list!");
            i=-2;
        }
        else
        {
            printf("\nElement at position %d is %d.", pos, current->data);
            i=-1;
        }
    }
    if(i==-1)
        return current->data;
    else
        return -1;
}


/* Driver program to test above function*/
int main()
{
    int choice=0, num, pos;
    while(choice !=5)
    {
        printf("\n\n1. Insert element at the end\t2. Print the list\t3. Search element\t4. Search by position\t5.EXIT");
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
            case 3: if(start==NULL)
                    printf("\nThe list is empty. Insert some elements before using this operation.");
                else
                {
                    printf("\nEnter element to be searched: ");
                    scanf("%d", &num);
                    pos = search_elt(num);
                    if(pos == -1)
                        printf("\n%d is not present in the list. ", num);
                    else
                        printf("\nThe first occurrence of %d is at position %d in the list. ", num, pos);
                }
                break;
            case 4:
                if(start==NULL)
                    printf("\nThe list is empty. Enter values before performing this operation. ");
                else
                {
                    printf("\nEnter position: ");
                    scanf("%d", &pos);
                    search_by_pos(pos);
                }
                break;
            case 5:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}