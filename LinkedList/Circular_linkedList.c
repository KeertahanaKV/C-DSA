#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
    int data;
    struct node* link;
};
struct clist
{
    struct node* head;
};
struct node* createnode(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->link=NULL;
    return newnode;
}

void display(struct clist* list)
{
    if(list->head->link==NULL)
    {
        printf("empty list\n");
        return;
    }
    struct node* current=list->head->link;
    do
    {
        printf("%d\t",current->data);
        current=current->link;
        
    }while(current!=list->head->link);
}
void createlist(struct clist *list)
{
     list->head=createnode(0);
}
void insertbystart(struct clist* list,int val)
{
    struct node* newnode=createnode(val);
    if(list->head->link==NULL)
    {
        list->head->link=newnode;
        newnode->link=newnode;
        count++;
        return;
   }
   struct node* current=list->head->link;
   while(current->link!=list->head->link)
   {
       current=current->link;
   }
   newnode->link=list->head->link;
   list->head->link=newnode;
   current->link=newnode;
   count++;
}
void insertbyrear(struct clist* list,int val)
{
    struct node* newnode=createnode(val);
    if(list->head->link==NULL)
    {
        list->head->link=newnode;
        newnode->link=newnode;
        count++;
        return;
   }
   struct node* current=list->head->link;
   while(current->link!=list->head->link)
   {
       current=current->link;
   }
  newnode->link=current->link;
  current->link=newnode;
   count++;
}
void insertbypos(struct clist* list, int pos, int val) {
    if (pos < 0 || pos > count-1) {
        printf("Invalid position\n");
        return;
    }
    struct node* newnode = createnode(val);
    struct node* current = list->head->link;
    if (pos == 0) {
        insertbystart(list,val);
        return;
    } 
    for(int i=1;i<pos && current->link!=list->head->link;i++)
    {
        current=current->link;
    }
    newnode->link=current->link;
    current->link=newnode;
    count++;
}
void deleteatfront(struct clist *list) {
if (list->head->link == NULL) {
   return;
}
struct node *current = list->head->link;
struct node *tail = current->link;
if (tail == current) {
list->head->link = NULL;
free(current);
count--;
}
else 
{
while (tail->link != list->head->link) {
tail = tail->link;
}
tail->link = current->link;
list->head->link = current->link;
free(current);
count--;
}
}
void deletetatend(struct clist* list)
{
    if (list->head->link == NULL) {
   return;
}
  struct node *current = list->head->link;
  struct node *prev = NULL;
  if(current->link==list->head->link)
  {
      list->head->link=NULL;
      free(current);
      count--;
      return;
  }
  while(current->link!=list->head->link)
  {
      prev=current;
      current=current->link;
  }
  prev->link=current->link;
  current->link=NULL;
  free(current);
  count--;
}
void deletetatpos(struct clist* list,int pos)
{
    if(pos<0|| pos>count-1)
    {
        printf("invalid position\n");
        return;
    }
    if(list->head->link==NULL)
    {
        printf("empty list\n");
        return;
    }
    if (pos == 0) {
       deleteatfront(list);
        return;
    } 
    struct node* current=list->head->link;
    struct node* prev=NULL;
    for(int i=0;i<pos;i++)
    {
        prev=current;
        current=current->link;
    }
    prev->link=current->link;
    free(current);
        count--;
}
int searchbykey(struct clist* list,int key)
{
    if(list->head->link== NULL)
    {
       return -1;
    }
    int pos=0;
    struct node* current=list->head->link;
    do
    {
        if(current->data==key)
        {
            return pos;
        }
        pos++;
        current=current->link;
    }while(current!=list->head->link);
    return -1;
}
void  deletebykey(struct clist* list,int key)
{
    int pos=searchbykey(list,key);
    if(pos!=-1)
    {
      deletetatpos(list,pos); 
    }
}
int searchbypos(struct clist* list,int pos)
{
    if(pos<0 || pos>count-1)
    {
        printf("ivlnavlid position\n");
        return -1;
    }
    if(list->head->link==NULL)
    {
        return -1;
    }
    struct node* current=list->head->link;

    for(int i=0;i<pos;i++)    
    {
        current=current->link;
    
    }
    return current->data;
}
void insertbyOrder(struct clist* list,int val){
    struct node* newnode = createnode(val);
    if(list->head->link == NULL){
        list->head->link = newnode;
        newnode->link = newnode;
        count++ ;
        return;
    }
    struct node* curr=list->head->link;
    struct node* tail = curr;
    while(tail->link != list->head->link)
        tail = tail->link;
    if(curr->data > val){
        newnode->link = list->head->link;
        list->head->link = newnode;
        tail->link = newnode;
       count++ ;
        return;
    }
    while(curr->link->data < val && curr->link != list->head->link)
        curr = curr->link;
    newnode->link = curr->link;
    curr->link = newnode;
    count++;
}
void  reverselist(struct clist* list)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return;
    }
    struct node* current=list->head->link;
    struct node* prev=NULL;
    struct node* next;
    do
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }while(current!=NULL);
    list->head->link->link=prev;
    list->head->link=prev;
    
}
void freelist(struct clist* list)
{
    struct node* current=list->head->link;
    struct node* next;
    while(current!=NULL)
    {
        next=current->link;
        free(current);
        current=next;
    }
}

int main()
{
    int choice,val,pos,key;
    struct clist* list;
   list=(struct clist*)malloc(sizeof(struct clist));
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
            return 0;
    default:
         printf("\nEnter the correct choice");
    }
}
return 0;
}

