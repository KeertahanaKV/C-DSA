//Representation of stack using linked list(Header node is included)

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *link;
    };

 struct Linkedlist{
    struct stack *head;
    };    
typedef struct stack stack;
typedef struct Linkedlist Llist;

void createList(Llist *list) {
    stack *h = (stack *)malloc(sizeof(stack));
    if (h ==NULL) {
        printf("Memory allocation failed...\n");
        exit(1);
    }
    h->data=0;
    h->link=NULL; 
    list->head= h;
}
void push(Llist *list,int val)  {
        stack *newnode=(stack *)malloc(sizeof(stack));
          if(newnode==NULL) {
              printf("Memory not allocated...\n");
              exit(1);
          }
        newnode->data=val;
        if(list->head->link==NULL)
            newnode->link=NULL;
        else
            newnode->link=list->head->link;
        list->head->link=newnode;
        }

void pop(Llist *list)  {
        if(list->head->link==NULL){
             printf("Stack is empty...\n");
             return ;
         }
         stack *temp =list->head->link;
         printf("Popped element is %d",temp->data);
         list->head->link=temp->link;
         free(temp);
        }

      void peek(Llist *list)  {
        if(list->head->link==NULL){
             printf("Stack is empty...\n");
             return ;
         }
         printf("Peek element is %d",list->head->link->data);
        }

     

    void display(Llist *list) {
        if(list->head->link==NULL){
             printf("Stack is empty...\n");
             return ;
         }

        stack *temp =list->head->link;
            while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->link;
            }

          printf("\n");
       }

  int main()
  {
    Llist S;
    createList(&S);
    int choice,key;
    do{
        printf("\nMenu\n0.Exit\n1.Push\t2.Pop\t3.Peek\t4.Display");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 0: printf("Exiting from the program\n");
                    break;

            case 1: printf("Enter the element to push into the stack : ");
                    scanf("%d",&key);
                    push(&S,key);
                    break;
            
            case 2: pop(&S);
                    break;
            
            case 3: peek(&S);
                    break;
            
            case 4: display(&S);
                    break;
            
            default: printf("Invalid choice...Please try again\n");
        }
    }while(choice!=0);

    return 0;
}

