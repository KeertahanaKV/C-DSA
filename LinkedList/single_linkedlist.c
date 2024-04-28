
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct slist
{
    struct node* head;
};
typedef struct node Node;
typedef struct slist List;

Node* createnode(int val)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL)
    {
        printf("Memory alloction not possible\n");
        exit(0);
    }
    newnode->data=val;
    newnode->link=NULL;
    return newnode;
}
void createlist(List* list)
{
    list->head=createnode(0);
}
void display(List* list)
{
    if(list->head->link==NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node* current=list->head->link;
    do
    {
        printf("%d\t",current->data);
        current=current->link;
    }while(current!=NULL);
}
void insertatfront(List* list,int val)
{
    Node* newnode=createnode(val);
    if(list->head->link==NULL)
    {
        list->head->link=newnode;
        return;
    }
    newnode->link=list->head->link;
    list->head->link=newnode;
    
}
void insertatend(List* list,int val)
{
    Node* newnode=createnode(val);
    Node* current=list->head->link;
    if(list->head->link==NULL)
    {
        list->head->link=newnode;
        return;
    }
    while(current->link!=NULL)
    {
        current=current->link;
    }
      current->link=newnode;
}
void insertatpos(List* list,int val,int pos)
{
    Node* newnode=createnode(val);
    Node* current=list->head->link;
    if(pos==0)
    {
     newnode->link=list->head->link;
     list->head->link=newnode;
     return;
    }
    for(int i=1;i<pos && current->link!=NULL;i++)
    {
        current=current->link;
    }
    if(current->link==NULL)
    {
        printf("Ivalid position\n");
        return;
    }
    newnode->link=current->link;
    current->link=newnode;
}
void deletetatfront(List* list)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node* current=list->head->link;
    list->head->link=current->link;
    free(current);
}
void deletetatend(List* list)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node* current=list->head->link;
    Node* prev=NULL;
    while(current->link!=NULL)
    {
        prev=current;
        current=current->link;
    }
    if (prev == NULL) 
    { // If there's only one node in the list
        list->head->link = NULL;
    } 
    else 
    {
        prev->link = NULL;
    }
    free(current);
    
}
void deletetatpos(List* list,int pos)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return;
    }
    
    if(pos==0)
    {
        deletetatfront(list);
        return;
    
    }
    Node* current=list->head->link;
    Node* prev=NULL;
    for(int i=0;i<pos && current!=NULL;i++)
    {
        prev=current;
        current=current->link;
    }
    if(current==NULL)
    {
        printf("Ivalid position\n");
        return;
    }
    prev->link=current->link;
    free(current);
    
}
int searchbykey(List* list,int key)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return -1;
    }
    Node* current=list->head->link;
    int pos=0;
    do
    {
        if(current->data==key)
        {
            return  pos;
        }
        pos++;
        current=current->link;
    }while(current!=NULL);
    return -1;
}
void deletebykey(List* list,int key)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return;
    }
    int pos=searchbykey(list,key);
    if(pos!=-1)
    {
        deletetatpos(list,pos);
        
    }
    else
    {
        printf("\nkey not found");
    }
    
}
void  reverselist(List* list)
{
    if(list->head->link==NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node* current=list->head->link;
    Node* prev=NULL;
    Node* next;
    do
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }while(current!=NULL);
    list->head->link=prev;
    
}
void freelist(List* list)
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
int main() {
    int choice,val,pos,key;
    List* list=(List*)malloc(sizeof(List));
    createlist(list);
    printf("\n0.Exit\n1.InsertatFront\n2.InsertatEnd\n3.InsertatPos\n4.Deleteatfront\n5.DeleteatEnd\n6.Deleteatpos\n7.SearchbyKey\n8.DeleteBykey\n9.ReverseList\n10.freeList");
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
              insertatfront(list,val);
              display(list);
              break;
         case 2:
              printf("Enter the value to insert:  ");
              scanf("%d",&val);
              insertatend(list,val);
              display(list);
              break;
        case 3:
              printf("Enter the value to insert:  ");
              scanf("%d",&val);
              printf("\nEnter the position:  ");
              scanf("%d",&pos);
              insertatpos(list,val,pos);
              display(list);
              break;
        case 4:
               deletetatfront(list);
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
             printf("the key %d found at pos %d",key,ans);
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
           reverselist(list);
           display(list);
           break;
    case 10:
            freelist(list);
            return 0;
    default:
         printf("\nEnter the correct choice");
    }
}
    return 0;
}
