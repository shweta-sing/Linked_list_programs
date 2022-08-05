#include<stdio.h>
#include <malloc.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
} list;
list *start = NULL;

typedef struct hash_map{
    list *add;
    struct hash_map *next;
} hash;


list* detect_loop(list *start)
{
    list *current=NULL, *loop_ptr = NULL, *loop_start = NULL;
    hash *current_hash=NULL, *last_node = NULL;
    hash *hash_start = NULL;
    int loop_found = 0, loop_length=0, first_hash = 0;//first_hash is used as flag to mark the creation of first hash block
    if(start==NULL)
        printf("\nThe list is empty. Add some elements before performing this operation");
    else
    {
        if(start->next==start)
        {
            loop_found = 1;
            loop_ptr = start;
            printf("\nA self loop is detected at first element.");
        }
        else
        {
            if(start->next==NULL)
            {
                printf("\nNo loop detected!");
            }
            else
            {
                current = start;
                while(current!=NULL)//loop to traverse list
                {
                    current_hash = hash_start;
                    while(current_hash!=NULL)//loop to traverse hash map
                    {
                        if(current_hash->add == current->next)
                        {
                            loop_ptr = current;
                            loop_found = 1;
                            break;
                        }
                        else
                            current_hash = current_hash->next;
                    }
                    if(loop_found==0&&current->next!=NULL)
                    {
                        hash *new = (hash*) malloc(sizeof(hash));
                        if(hash_start == NULL)
                        {
                            new->add = current;
                            new->next = NULL;
                            hash_start = new;
                            last_node = new;
                            first_hash = 1;
                        }
                        else
                        {
                            new->add = current->next;
                            new->next = NULL;
                            last_node->next = new;
                            last_node = last_node->next;
                            first_hash = 0;
                        }
                    }
                    else
                    {
                        if(loop_found == 1)
                            break;
                    }
                    if(first_hash==0)//added this variable so start node of list gets through inner while loop
                        current = current->next;
                }

                if(loop_found==1)//loop detected in the list
                {
                    current = loop_ptr->next;
                    if(current==loop_ptr)
                    {
                        printf("\nA self loop detected at %d.", current->data);
                    }
                    else
                    {
                        printf("\nLoop detected between %d and %d.",loop_ptr->data, loop_ptr->next->data);
                        printf("\n%d is pointing towards %d, thus creating a loop.",loop_ptr->data, loop_ptr->next->data);
                        if(current->next == loop_ptr)//to find length of the loop
                        {
                            loop_length = 2;
                            printf("\nLength of the loop is %d.", loop_length);
                        }
                        else
                        {
                            loop_start = current;
                            current = current->next;
                            loop_length = 2;
                            while (current->next!= loop_start)//to find length of the loop
                            {
                                current = current->next;
                                loop_length++;
                            }
                            printf("\nLength of the loop is %d.", loop_length);
                        }
                    }
                }
                else
                    printf("\nNo loop detected in the list!");
            }
        }
    }
    if(loop_found==1)
        return loop_ptr;
    else
        return NULL;
}

int main()
{
    int choice, num;
    list *node = (list*)malloc(sizeof(list));
    node->next = NULL;
    node->data = 10;
    start = node;
    list *node1 = (list*)malloc(sizeof(list));
    node1->data = 20;
    node->next = node1;
    list *node2 = (list*)malloc(sizeof(list));
    node2->data = 30;
    node1->next = node2;
    list *node3 = (list*)malloc(sizeof(list));
    node3->data = 40;
    node2->next = node3;
    list *node4 = (list*)malloc(sizeof(list));
    node4->data = 50;
    node3->next = node4;
    node4->next = node; //loop between last and first node

    //Following cases can be tried for various loop sizes and positions.
    // Make sure to comment out the previous statement that is creating loop, before uncommenting the below ones.
    //Make sure to keep only one loop at a time.
    //node4->next = node4; //self loop at last node
    //node->next = node; //self loop at first node
    //node->next = node1; //loop between adjacent nodes, loop of length 2. Uncomment this statement and the one below it before executing.
    //node1->next = node; //uncomment this statement and the one just above it before execution.

    while(choice!=2)
    {
        printf("\n\n1. Detect loop\t2.EXIT");
        printf("\nChoose an option from the menu: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                detect_loop(start);
                break;
            case 2:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}
