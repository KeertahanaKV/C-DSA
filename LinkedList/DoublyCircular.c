#include <stdio.h>
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
void createlist(struct dclist *list)
{
     list->head=createNode(0);
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
void insertbystart(struct dclist* list,int val)
{
 struct node *newNode = createNode(val);
 if (list->head->nlink == NULL)
 {
  list->head->nlink = newNode;
  newNode->nlink = newNode;
  newNode->plink = newNode;
} 
else {
struct node *last = list->head->nlink->plink;
last->nlink = newNode;
newNode->nlink = list->head->nlink;
newNode->plink = last;
list->head->nlink = newNode;
}
count++;
}
void insertbyrear(struct dclist* list,int val)
{
    struct node *newNode = createNode(val);
  if (list->head->nlink == NULL)
  {
    list->head->nlink = newNode;
   newNode->nlink = newNode;
   newNode->plink = newNode;
   count++;
   return;
}
struct node *last = list->head->nlink->plink;
last->nlink = newNode;
newNode->plink = last;
newNode->nlink = list->head->nlink;
list->head->nlink->plink = newNode;
count++;
}
void insertbypos(struct dclist* list,int val,int pos)
{
     if (pos < 0 || pos > count-1) 
     {
        printf("Invalid position\n");
        return;
    }
    if (pos == 0) 
    {
        insertbystart(list,val);
        return;
    }
    struct node *newNode = createNode(val);
   struct node *current = list->head->nlink;
for (int i = 1; i < pos; i++)
{
 current = current->nlink;
}
newNode->nlink = current->nlink;
newNode->plink = current;
current->nlink->plink = newNode;
current->nlink = newNode;
count++;
}
void deleteatfront(struct dclist* list)
{
     if (list->head->nlink == NULL) 
     {
     printf("List is empty.\n");
     return;
     }
 struct node *current = list->head->nlink;
   struct node *last = current->plink;
   if (current == last) {
     list->head->nlink = NULL;
} 
else {
last->nlink = current->nlink;
current->nlink->plink = last;
list->head->nlink = current->nlink;
}
count--;
free(current);
}
void deletetatend(struct dclist *list)
{
    if (list->head->nlink == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
}
struct node *current = list->head->nlink;
struct node *last = current->plink;
struct node *last2 = last->plink;
if (current == last) {
list->head->nlink = NULL;
} else {
last2->nlink = list->head->nlink;
list->head->nlink->plink = last2;
}
count--;
free(last);
}
void deletetatpos(struct dclist* list,int pos)
{
    if(pos<0|| pos>count-1)
    {
        printf("invalid position\n");
        return;
    }
    if(list->head->nlink==NULL)
    {
        printf("empty list\n");
        return;
    }
    if (pos == 0) {
       deleteatfront(list);
        return;
    } 
   struct node *current = list->head->nlink;
    struct node *previous = NULL;
   for (int i = 0; i < pos; i++) {
     previous = current;
     current = current->nlink;
}

previous->nlink = current->nlink;
current->nlink->plink = previous;
free(current);
count--;
}
int searchbykey(struct dclist* list, int key)
{
     if (list->head->nlink == NULL)
    {
        printf("Empty list\n");
        return -1;
    }
    struct node *current = list->head->nlink;
    int pos = 0;
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
void deletebykey(struct dclist* list,int key)
{
    int pos=searchbykey(list,key);
    if(pos!=-1)
    {
      deletetatpos(list,pos); 
    }
}
int searchbypos(struct dclist* list,int pos)
{
     if (pos < 0 || pos > count-1)
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
    for (int i = 0; i < pos; i++)
    {
        current = current->nlink;
    }
    return current->data;
}
void reverselist(struct dclist* list)
{
    if(list->head->nlink == NULL){
printf("List is empty. Cannot reverse.\n");
return;
}
 struct node *current = list->head->nlink;
 struct node *next = NULL;
do {
next = current->nlink;
current->nlink = current->plink;
current->plink = next;
next->plink = current;
current = current->plink;
} while (current != list->head->nlink);
list->head->nlink = current->nlink;
}
void freeList(List *list) {
if (list->head->nlink == NULL){
free(list->head);
free(list);
return;
}
struct node* current = list->head->nlink;
do {
struct node *temp = current;
current = current->nlink;
free(temp);
} while (current->nlink != list->head->nlink);
free(current);
free(list->head);
free(list);
}
int main()
{
    int choice,val,pos,key;
    struct dclist* list;
   list=(struct dclist*)malloc(sizeof(struct dclist));
   createlist(list);
    printf("\n0.Exit\n1.InsertatFront\n2.InsertatEnd\n3.InsertatPos\n4.Deleteatfront\n5.DeleteatEnd\n6.Deleteatpos\n7.SearchbyKey\n8.DeleteBykey\n9.SearchBypos\n10.InsertByorder\n11.ReverseList\n12.freeList");
    while(1)
    {
    printf("\nEnter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 0:return 0;
        case 1:
              printf("Enter the value to insert:  ");
              scanf("%d",&val);
              insertbystart(list,val);
              display(list);
              break;
         case 2:
              printf("Enter the value to insert:  ");
              scanf("%d",&val);
              insertbyrear(list,val);
              display(list);
              break;
        case 3:
              printf("Enter the value to insert:  ");
              scanf("%d",&val);
              printf("Enter the position:  ");
              scanf("%d",&pos);
              insertbypos(list,val,pos);
              display(list);
              break;
      case 4:
               deleteatfront(list);
               display(list);
               break;
     case 5:
               deletetatend(list);
               display(list);
               break;
     case 6:
            printf("\nEnter the position to delete:  ");
            scanf("%d",&pos);
            deletetatpos(list,pos);
               display(list);
               break;
     case 7:
        int ans;
        printf("Enter the Key value to search: ");
        scanf("%d",&key);
         ans=searchbykey(list,key);
         if(ans!=-1)
         {
             printf("Key %d found at pos %d",key,ans);
         }
         else
         {
             printf("key not found\n");
         }
        break;
   case 8:
            printf("Enter the Key value to delete: ");
           scanf("%d",&key);
           deletebykey(list,key);
           display(list);
           break;
    case 9:
           printf("enter the position:  ");
            scanf("%d",&pos);
            key=searchbypos(list,pos);
            if(key!=-1)
            {
             printf("%d found at position %d",key,pos);
            }
          break;
    case 10:
            printf("Enter the value to insert:  ");
              scanf("%d",&val);
              insertbyOrder(list,val);
              display(list);
              break;
    
    case 11:
           reverselist(list);
           display(list);
           break;
    case 12:
            freelist(list);
           
    default:
         printf("\nEnter the correct choice");
    }
}
return 0;
}
