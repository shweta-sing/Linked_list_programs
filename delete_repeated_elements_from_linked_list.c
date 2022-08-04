#include<stdio.h>
#include <malloc.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
} list;
list *start = NULL;

typedef struct hash_map{
    int data;
    int freq ;
    struct hash_map *next;
} hash;
hash *hash_start = NULL;


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

int del_repeated(list *start)
{
    list *current, *check, *temp;
    int flag = 0; //flag to check if deletion happened or not
    int occurrences = 1;
    if(start==NULL)
    {
        printf("\nThe list is empty. Enter some elements before performing this operation.");
        flag = -1;
    }
    else
    {
        if(start->next == NULL)
        {
            printf("\nList has only one element. No scope of repetition. ");
            flag = -2;
        }
        else
        {
            current = start;
            while(current->next!=NULL)
            {
                check = current;
                while(check->next!=NULL)
                {
                    if(current->data == check->next->data)
                    {
                        flag++;
                        occurrences++;
                        if(flag==1)
                        {
                            printf("\nThe original list was: ");
                            print_list();
                        }
                        temp = check->next;
                        check->next = temp->next;
                        temp->next = NULL;
                        free(temp);
                        temp = NULL;
                    }
                    else
                        check = check->next;
                }
                if(occurrences!= 1)
                {
                    printf("\nThere were %d occurrences of %d.", occurrences, current->data);
                }
                current = current->next;
                occurrences = 1;
            }
        }
    }
    if(flag>=1)
    {
        printf("\nDuplicate elements have been deleted successfully. ");
        printf("\nThe updated list is below:");
        print_list();
        return 1;
    }
    else
    {
        if(flag==0)
        {
            printf("\nNo duplicates found in the list!");
            print_list();
            return 0;
        }
    }

}

int main()
{
    int choice, num;
    while(choice!=4)
    {
        printf("\n1. Insert element at the end\t2. Print the list\t3. Delete repeated elements\t4.EXIT");
        printf("\n\nChoose an option from the menu: ");
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
                del_repeated(start);
                break;
            case 4:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}