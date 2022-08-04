#include<stdio.h>
#include <malloc.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
} list;
list *start = NULL;

int insert_beg(int num)
{
    list *node = (list*)malloc(sizeof(list));
    node->next = NULL;
    node->data = num;

    if(start==NULL)
        start = node;
    else{
        node->next = start;
        start = node;
    }
    printf("\nValue inserted successfully.\n");
}

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

int insert_pos(int num, int pos) {
    int p = 1;
    list *current;
    int overflow = 0;
    if(pos<=0){
        printf("\nPosition can't be 0. Enter a positive integer.");
    }
    else
    {
        if (start == NULL&&pos>1)
            printf("\nThe list is empty. Insert some elements ");
        else
        {
            if(pos==1&&start!=NULL)
            {
                list *node = (list *) malloc(sizeof(list));
                node->data = num;
                node->next = start;
                start= node;
                overflow++;
                printf("\nElement inserted successfully.\n");
            }
            else
            {
                if(pos==1&&start==NULL)
                {
                    list *node = (list *) malloc(sizeof(list));
                    node->data = num;
                    node ->next = NULL;
                    start= node;
                    overflow++;
                    printf("\nElement inserted successfully.\n");
                }
                else
                {
                    if(pos==2)
                    {
                        list *node = (list *) malloc(sizeof(list));
                        node->data = num;
                        node->next = start->next;
                        start->next = node;
                        overflow++;
                        printf("\nElement inserted successfully.\n");
                    }
                    else
                    {
                        current = start;
                        for (p; p < pos - 1; p++)
                        {
                            current = current->next;
                            if (current == NULL) {
                                printf("\nPosition is greater than the number of elements in the list.");
                                overflow++;
                                break;
                            }
                        }

                    }
                }
            }


            if (overflow==0)
            {
                list *node = (list *) malloc(sizeof(list));
                node->data = num;
                node->next = current->next;
                current->next = node;
                printf("\nElement inserted successfully.\n");
            }
        }
    }
    return 1;
}


int insert_by_elt(list *position, int num)
{
    list *current;
    list* node = (list*) malloc(sizeof(list));
    node->data = num;
    node->next = position->next;
    position->next = node;
    printf("\n%d inserted successfully after %d. ",num, position->data);
    return 1;
}



int delete_beg()
{
    int num;
    list *current;
    if(start==NULL)
        printf("\nList is empty. Nothing to delete.");
    else
    {
        if(start->next==NULL){
            num = start->data;
            free(start);
            start = NULL;
        }
        else{
            num = start->data;
            current = start;
            start = start->next;
            free(current);
            current = NULL;
        }
        printf("\nThe first element is %d. Element deleted successfully.\n", num);
    }
}

int delete_end()
{
    int num;
    list *current;
    if(start==NULL)
        printf("\nList is empty. Nothing to delete.");
    else
    {
        if(start->next==NULL)
        {
            num = start->data;
            free(start);
            start = NULL;
        }
        else
        {
            if(start->next->next == NULL)
            {
                free(start->next);
                start->next = NULL;
            }
            else{
                current = start;
                while(current->next->next!= NULL)
                    current = current->next;
                num = current->next->data;
                free(current->next);
                current->next = NULL;
            }
        }
        printf("\nThe last element is %d. Element deleted successfully\n", num);
    }
}

int delete_pos(int pos)
{
    list *current, *temp;
    int del_elt; //To hold the deleted element
    int p = 1;
    int overflow = 0;
    if(pos<1)
    {
        printf("\nPosition can't be 0. Enter a positive  integer.");
        overflow--;
    }
    else{
        if(start == NULL)
        {
            printf("\nList is empty. Nothing to delete.");
            overflow--;
        }
        else
        {
            if(pos==1)
            {
                if(start->next==NULL)
                {
                    del_elt = start->data;
                    free(start);
                    start = NULL;
                    printf("\nElement deleted successfully.");
                }
                else
                {
                    del_elt = start->data;
                    current = start->next;
                    free(start);
                    start = current;
                    printf("\nElement deleted successfully.");
                }
            }
            else
            {
                if(pos==2)
                {
                    if(start->next == NULL)
                    {
                        printf("\nPosition is greater than the number of elements in the list.");
                        overflow--;
                    }
                    else
                    {
                        del_elt = start->next->data;
                        current = start->next;
                        start->next = current->next;
                        free(current);
                        current = NULL;
                        printf("\nElement deleted successfully.");
                    }
                }
                else
                {
                    current = start;
                    while(p<pos-1)
                    {
                        current = current -> next;
                        if(current == NULL)
                        {
                            printf("\nPosition is greater than the number of elements in the list.");
                            overflow--;
                            break;
                        }
                        p++;
                    }
                    if(overflow==0)
                    {
                        if (current->next == NULL) {
                            printf("\nPosition is greater than the number of elements in the list. Try again.");
                            overflow--;
                        } else
                        {
                            temp = current->next;
                            del_elt = temp->data;
                            current->next = temp->next;
                            free(temp);
                            temp = NULL;
                            printf("\nElement deleted successfully.");
                        }

                    }
                }
            }
        }
    }
    if(overflow==0)
        return del_elt;
    else
        return -1;
}


int delete_by_elt(list *position, int num)
{
    list *current, *temp;
    int i=1; //to calculate element_to_be_deleted's position
    if(position==start)
    {
        current = start->next;
        free(start);
        start = current;
    }
    else
    {
        current = start;
        while(current->next!=position)
        {
            current = current->next;
            i++;
        }
        current->next = position->next;
        free(position);
        position = NULL;
        i++;
    }
    printf("\n%d was at position %d. Deleted successfully.", num, i);
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

list* search_elt(int elt, int print_flag)
{
    list *current;
    int i =0;
    int overflow=0;
    if(start==NULL)
        overflow--;
    else
    {
        current = start;
        while(current!=NULL)
        {
            i++;
            if(current->data == elt)
            {
                overflow++;
                break;
            }
            current = current->next;
        }
    }
    if(overflow==1)
    {
        if(print_flag==1)
            printf("\nElement found in the list at position %d.", i);
        return current;
    }
    else
    {
        if(print_flag==1)
            printf("\nElement is not present in the list!!!");
        return NULL;
    }
}

int reverse_list()
{
    list *current, *temp, *start2, *end;
    int flag=1; //to mark start of the reversed list
    if(start==NULL)
        printf("\nList is empty. Add elements to the list before performing this operation. ");
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
        printf("\nRotation of list is successful.");
    }
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


int main()
{
    int choice, num, pos, elt, print_flag=-1;
    list *position;
    while(1)
    {
        printf("\n1.  Insert element at the beginning   \t2.  Insert element at the end         \t3.  Insert by position");
        printf("\n4.  Insert after to specific element  \t5.  Delete element at the beginning   \t6.  Delete element at the end");
        printf("\n7.  Delete by position                \t8.  Delete a specific element         \t9.  Print the list");
        printf("\n10. Reverse the list                  \t11. Find an element                   \t12. Find element by position");
        printf("\n13. EXIT");
        printf("\n\nChoose an option from the menu:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter value: ");
                scanf("%d", &num);
                insert_beg(num);
                break;
            case 2: printf("\nEnter value: ");
                scanf("%d",&num);
                insert_end(num);
                break;
            case 3: printf("\nEnter value: ");
                    scanf("%d",&num);
                    printf("\nEnter position: ", pos);
                    scanf("%d",&pos);
                    insert_pos(num, pos);
                    break;
            case 4:
                if(start==NULL)
                    printf("\nThe list is empty. Insert some elements before using this operation.");
                else
                {
                    printf("\nEnter element present in the list after which new element needs to be added.");
                    scanf("%d", &elt);
                    print_flag=-1;
                    position = search_elt(elt, print_flag);
                    if(position == NULL)
                        printf("\n%d is not present in the list. Enter a valid element.", elt);
                    else
                    {
                        printf("\nEnter value to be inserted: ");
                        scanf("%d", &num);
                        insert_by_elt(position, num);
                        position = NULL;
                    }
                }
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                if(start==NULL)
                    printf("\nList is empty. Nothing to delete.");
                else
                {
                    printf("\nEnter position of element to be deleted: ");
                    scanf("%d", &pos);
                    delete_pos(pos);
                }
                break;
            case 8:
                if(start==NULL)
                    printf("\nList is empty. Nothing to delete.");
                else
                {
                    printf("\nEnter element which needs to be deleted: ");
                    scanf("%d", &elt);
                    print_flag=-1;
                    position = search_elt(elt, print_flag);
                    if(position == NULL)
                        printf("\n%d is not present in the list. Enter a valid element.", elt);
                    else
                    {
                        delete_by_elt(position, elt);
                        position = NULL;
                    }
                }
                break;
            case 9:
                print_list();
                break;
            case 10:
                reverse_list();
                break;
            case 11: if(start==NULL)
                    printf("\nThe list is empty. Insert some elements before using this operation.");
                else
                {
                    printf("\nEnter element to be searched: ");
                    scanf("%d", &elt);
                    print_flag=1;
                    position = search_elt(elt, print_flag);
                }
                break;
            case 12:
                if(start==NULL)
                    printf("\nThe list is empty. Enter values before performing this operation. ");
                else
                {
                    printf("\nEnter position: ");
                    scanf("%d", &pos);
                    search_by_pos(pos);
                }
                break;
                case 13:
                printf("\nExit successful!");
                break;
            default:
                printf("\nEnter correct choice");
        }
    }
}