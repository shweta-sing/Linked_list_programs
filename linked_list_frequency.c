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

int show_hash_freq(hash *start);

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

int show_freq(list *ptr)
{
    list *current;
    hash *current_hash = NULL;
    int found = 0;
    if(start==NULL)
        printf("\nList is empty. Enter some elements before performing this operation.");
    else
    {
        current = start;
        while(current!=NULL)
        {
            if(hash_start==NULL)
            {
                printf("\nEntered if....123");
                hash *col = (hash*) malloc(sizeof (hash));
                printf("\nhash *col = (hash*) malloc(sizeof (hash));");
                col -> next = NULL;
                printf("\ncol -> next = NULL;");
                col -> data = start -> data;
                printf("\ncol -> data = start -> data;");
                col -> freq = 1;
                printf("\ncol -> freq = 1;");
                hash_start = col;
                printf("\nEnd of if....123");
            }
            else
            {
                current_hash = hash_start;
                if(current_hash->next == NULL)
                {
                    if(current->data == current_hash->data)
                        current_hash -> freq++;
                    else
                    {
                        hash *col = (hash*) malloc(sizeof (hash));
                        col -> next = NULL;
                        col -> data = current -> data;
                        col -> freq = 1;
                        current_hash -> next = col;
                    }
                }
                else
                {
                   // current_hash = hash_start;
                    while(current_hash->next !=NULL)
                    {
                        if(current->data == current_hash->data)
                        {
                            current_hash -> freq++;
                            found = 1;
                            break;
                        }
                        else
                            current_hash = current_hash->next;
                    }
                    if(found != 1)
                    {
                        if(current->data == current_hash->data)
                            current_hash -> freq++;
                        else
                        {
                            hash *col = (hash*) malloc(sizeof (hash));
                            col -> next = NULL;
                            col -> data = current -> data;
                            col -> freq = 1;
                            current_hash -> next = col;
                        }
                    }
                }
                found = 0;
            }
            current = current-> next;
        }
        show_hash_freq(hash_start);
    }
    return 1;
}

int show_hash_freq(hash *start)
{
    int i =1;
    hash *current;
    if(start==NULL)
        printf("\nList is empty. Nothing to display.");
    else
    {
        current = start;
        printf("\nKey\tFrequency");
        while(current != NULL)
        {
            printf("\n%d\t%d ",current->data, current->freq);
            current = current->next;
        }
    }
    return 1;
}

int main()
{
    int choice, num;
    while(choice!=9)
    {
        printf("\n1. Insert element at the end\t2. Print the list\t3. Show element frequency\t4.EXIT");
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
                show_freq(start);
                break;
            case 4:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}