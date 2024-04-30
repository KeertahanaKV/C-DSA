include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int data;
    struct node *nlink;
    struct node *plink;
};

struct dclist
{
    struct node *head;
};

struct node *createNode(int val)
{
    struct node *list = (struct node *)malloc(sizeof(struct node));
    list->data = val;
    list->nlink = NULL;
    list->plink = NULL;
    return list;
}

void display(struct dclist *list)
{
    if (list->head->nlink == NULL)
    {
        printf("empty list\n");
        return;
    }
    struct node *current = list->head->nlink;
    do
    {
        printf("%d\t", current->data);
        current = current->nlink;
    } while (current != list->head->nlink);
}

void insertByOrder(struct dclist *list, int val)
{
    struct node *newnode = createNode(val);
    if (list->head->nlink == NULL)
    { // If list is empty
        list->head->nlink = newnode;
        newnode->nlink = newnode->plink = newnode; // Circular link to itself
        count++;
        return;
    }

    struct node *current = list->head->nlink;
    struct node *prev = NULL;

    // Traverse the list to find the correct position to insert
    do
    {
        if (current->data >= val)
        {
            break; // Found the correct position to insert
        }
        prev = current;
        current = current->nlink;
    } while (current != list->head->nlink);

    // Insert newnode between prev and current
    if (prev == NULL)
    { // Insert at the beginning
        struct node *last = list->head->nlink->plink;
        newnode->nlink = list->head->nlink;
        newnode->plink = last;
        last->nlink = newnode;
        list->head->nlink->plink = newnode;
        list->head->nlink = newnode;
    }
    else
    { // Insert in the middle or at the end
        prev->nlink = newnode;
        newnode->plink = prev;
        newnode->nlink = current;
        current->plink = newnode;
    }
    count++;
}

void deleteByPosition(struct dclist *list, int pos)
{
    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }
    if (list->head->nlink == NULL)
    {
        printf("Empty list\n");
        return;
    }
    struct node *current = list->head->nlink;
    struct node *prev = NULL;
    for (int i = 1; i < pos; i++)
    {
        prev = current;
        current = current->nlink;
    }
    if (prev == NULL)
    {
        if (current->nlink == list->head->nlink)
        {
            list->head->nlink = NULL;
        }
        else
        {
            list->head->nlink = current->nlink;
            current->nlink->plink = current->plink;
            current->plink->nlink = current->nlink;
        }
    }
    else
    {
        prev->nlink = current->nlink;
        current->nlink->plink = prev;
    }
    free(current);
    count--;
}

int searchByPosition(struct dclist *list, int pos)
{
    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return -1;
    }
    if (list->head->nlink == NULL)
    {
        printf("empty list");
        return -1;
    }
    struct node *current = list->head->nlink;
    for (int i = 1; i < pos; i++)
    {
        current = current->nlink;
    }
    return current->data;
}

void deleteByKey(struct dclist *list, int key)
{
    if (list->head->nlink == NULL)
    {
        printf("Empty list\n");
        return;
    }
    struct node *current = list->head->nlink;
    struct node *prev = NULL;
    do
    {
        if (current->data == key)
        {
            if (prev == NULL)
            { // If the node to be deleted is the first node
                if (current->nlink == current)
                { // If it's the only node in the list
                    list->head->nlink = NULL;
                }
                else
                {
                    list->head->nlink = current->nlink;
                    current->nlink->plink = current->plink;
                    current->plink->nlink = current->nlink;
                }
            }
            else
            {
                prev->nlink = current->nlink;
                current->nlink->plink = prev;
            }
            free(current);
            count--;
            return;
        }
        prev = current;
        current = current->nlink;
    } while (current != list->head->nlink);
    printf("Key not found\n");
}

int searchByKey(struct dclist *list, int key)
{
    if (list->head->nlink == NULL)
    {
        printf("Empty list\n");
        return -1;
    }
    struct node *current = list->head->nlink;
    int pos = 1;
    do
    {
        if (current->data == key)
        {
            return pos;
        }
        current = current->nlink;
        pos++;
    } while (current != list->head->nlink);
    printf("Key not found\n");
    return -1;
}
int main()
{
    struct dclist *mylist;
    mylist = (struct dclist *)malloc(sizeof(struct dclist));
    mylist->head = createNode(0); // Initialize head

    int choice, val, pos, key;

    do
    {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. Insert by order\n");
        printf("2. Delete by position\n");
        printf("3. Search by position\n");
        printf("4. Delete by key\n");
        printf("5. Search by key\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert by order: ");
            scanf("%d", &val);
            insertByOrder(mylist, val);
            display(mylist);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteByPosition(mylist, pos);
            display(mylist);
            break;
        case 3:
            printf("Enter position to search: ");
            scanf("%d", &pos);
            printf("Value at position %d: %d\n", pos, searchByPosition(mylist, pos));
            break;
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteByKey(mylist, key);
            display(mylist);
            break;
        case 5:
            printf("Enter key to search: ");
            scanf("%d", &key);
            pos = searchByKey(mylist, key);
            if (pos != -1)
                printf("Key %d found at position %d\n", key, pos);
            break;
        case 6:
            display(mylist);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 7);

    return 0;
}
