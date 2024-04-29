#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node{
    int data;
    struct node* link;
};
struct clist{
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
void  insertbyorder(struct clist *list,int val)
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
    struct node* prev=NULL;
    do
    {
        if(current->data >= val)
        {
            if(prev==NULL)
            {
                 newnode->link=list->head->link;
                 list->head->link=newnode;
                 struct node* last=current;
                 while(last->link!=current)
                 {
                     last=last->link;
                 }
                 last->link=list->head->link;
            }
            else
            {
                prev->link=newnode;
                newnode->link=current;
            }
            count++;
            return;
        }
        prev=current;
        current=current->link;
    }while(current!=list->head->link);
    prev->link=newnode;
    newnode->link=current;
    count++;
}
void deletebypos(struct clist* list,int pos)
{
    if(pos<1|| pos>count)
    {
        printf("invalid position\n");
        return;
    }
    if(list->head->link==NULL)
    {
        printf("empty list\n");
        return;
    }
    struct node* current=list->head->link;
    struct node* prev=NULL;
    for(int i=1;i<pos;i++)
    {
        prev=current;
        current=current->link;
    }
    if(prev==NULL)
    {
       if(current->link==list->head->link)
       {
           list->head->link=NULL;
       }
       else
       {
           list->head->link=current->link;
           struct node* last=current;
                 while(last->link!=current)
                 {
                     last=last->link;
                 }
                 last->link=list->head->link;
           }

        free(current);
        count--;
        return;
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
    int pos=1;
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
    printf("key elemnt not found\n");
    return -1;
}
void  deletebykey(struct clist* list,int key)
{
    int pos=searchbykey(list,key);
    if(pos!=-1)
    {
       deletebypos(list,pos); 
    }
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
void delebykey(struct clist* list,int key)
{
    if(list->head->link==NULL)
    {
        return;
    }
    struct node* prev=NULL;
    struct node* current=list->head->link;
    do
    {
       if(current->data==key)
       {
          if(prev==NULL)
          {
              if(list->head->link==current->link)
              {
                 list->head->link=NULL; 
              }
              else
              {
                  struct node* last=current;
                  while(last->link!=current)
                  {
                      last=last->link;
                  }
                      list->head->link=current->link;
                      last->link=list->head->link;
                  
             }
          }
       else
       {
           prev->link=current->link;
       }
       printf("key %d deleted\n",key);
       free(current);
       count--;
       return;
       }
       
       prev=current;
      current=current->link;
    }while(current!=list->head->link);
    printf("key not found\n");
}
int searchbypos(struct clist* list,int pos)
{
    if(pos<1 || pos>count)
    {
        printf("ivlnavlid position\n");
        return -1;
    }
    if(list->head->link==NULL)
    {
        return -1;
    }
    struct node* current=list->head->link;

    for(int i=1;i<pos;i++)    
    {
        current=current->link;
    
    }
    return current->data;
}
void insertbypos(struct clist* list, int pos, int val) {
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position\n");
        return;
    }
    struct node* newnode = createnode(val);
    struct node* current = list->head->link;
    struct node* prev = NULL;
    
    if (pos == 1) {
        if (current == NULL) { // Insertion in an empty list
            list->head->link = newnode;
            newnode->link = newnode;
        } else {
            newnode->link = current;
            list->head->link = newnode;
            // Update the last node's link to point to the new first node
            while (current->link != list->head->link) {
                current = current->link;
            }
            current->link = newnode;
        }
    } else {
        int currentpos = 1;
        while (currentpos < pos) {
            prev = current;
            current = current->link;
            currentpos++;
        }
        newnode->link = current;
        prev->link = newnode;
    }
    count++;
}

int main()
{
    int choice,val,pos,key;
   struct clist* list;
   list=(struct clist*)malloc(sizeof(struct clist));
   list->head=createnode(0);
   while(1)
   {
       
       printf("\n1.insertbyorder\n2.deletebyposition\n3.searchbykey\n4.deletebykey\n5.inseratstart\n6.insertatrear\n7.delete by key\n8.searchbypos\n9.insertbypos\n");
       printf("\n\nenter your choice:  ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
                  printf("\nenter the value to be inserted:  ");
                  scanf("%d",&val);
                  insertbyorder(list,val);
                  display(list);
                  break;
          case 2:
                 printf("\nenter the position to be deleted:  ");
                  scanf("%d",&pos);
                  deletebypos(list,pos);
                  display(list);
                  break;
         case 3:
                 printf("\nenter the key to be searched:  ");
                  scanf("%d",&key);
                  pos=searchbykey(list,key);
                  if(pos!=-1)
                  {
                      printf("%d key found at position %d",key,pos);
                  }
                  display(list);
                  break;
        case 4:
               printf("\nenter the key to be deleted:  ");
                  scanf("%d",&key);
                  deletebykey(list,key);
                  display(list);
                  break;
        case 5:
                  printf("\nenter the value to be inserted:  ");
                  scanf("%d",&val);
                  insertbystart(list,val);
                  display(list);
                  break;
       case 6:
                  printf("\nenter the value to be inserted:  ");
                  scanf("%d",&val);
                  insertbyrear(list,val);
                  display(list);
                  break;
        case 7: 
               printf("enter the key to be deleted:  ");
               scanf("%d",&key);
               delebykey(list,key);
               display(list);
               break;
        case 8: 
                printf("enter the position:  ");
                scanf("%d",&pos);
                key=searchbypos(list,pos);
                if(key!=-1)
                {
                    printf("%d found at position %d",key,pos);
                }
                break;
        case 9: printf("\nenter the value to be inserted:  ");
                  scanf("%d",&val);
               printf("enter te position:  ");
                scanf("%d",&pos);
                insertbypos(list,pos,val);
                display(list);
                break;
       }
   }
}
