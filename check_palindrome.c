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

int is_palindrome(list *start)
{
    list *temp;
    list *end=NULL, *previous=NULL, *temp2;
    int length=0, is_palin = 0, i =0;
    if(start==NULL)
    {
        printf("\nList is empty. Insert some elements before performing this operation. ");
        return 0;
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        if(length==1)
            is_palin = 1;
        else
        {
            length = length/2;
            temp = start;
            while(i<length)
            {
                temp2 = start;
                if(end==NULL)
                {
                    while(temp2->next->next!=end)
                        temp2 = temp2 -> next;
                }
                else
                {
                    while(temp2->next!=end)
                        temp2 = temp2 -> next;
                }
                if(temp->data == temp2->next->data)//value matched
                    end = temp2;
                else
                    break;

                i++;
                if(i<length)
                    temp = temp->next;
            }
            if(i==length)//to check if the last values were matched or not
            {
                if(temp->data == temp2->next->data)
                    is_palin = 1;
            }
        }
    }
    if(is_palin==1)
        return 1;
    else
        return -1;
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



int main()
{
    int choice, num, output;
    while(choice!=4)
    {
        printf("\n\n1. Insert element at the end\t2. Print the list\t3. Check palindrome\t4.EXIT");
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
                output = is_palindrome(start);
                if(output==1)
                    printf("\nThe list is a palindrome.");
                else
                {
                    if(output==-1)
                        printf("\nNot a palindrome.");
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