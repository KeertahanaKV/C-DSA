#include<stdio.h>
#include<stdlib.h>


void display(int *arr,int size)
{
   printf("\n___________________________________________\n");
   printf("Updated Array elements are:\n ");
   for(int i=0;i<size;i++)
   printf("%d  ",*(arr+i));
   printf("\n___________________________________________\n");
}


void insertbyPos(int *arr,int *size,int pos,int val)
{
    if(pos>=0 && pos<=*size)
    {
     for(int i=*size-1;i>=pos;i--)
     *(arr+i+1)=*(arr+i);

     *(arr+pos)=val;
     *size+=1;
    }
    else
     printf("Invalid Position..\n");
}


void deletebyPos(int *arr,int *size,int pos)
{
    if(pos>=0 && pos<*size)
    {
     for(int i=pos;i<*size;i++)
     *(arr+i)=*(arr+i+1);

     *size-=1;
    }
    else
     printf("Invalid Position..\n");
}


int searchElement(int *arr,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)==key) return i;
    }
    return -1;
}

void deletebykey(int *arr,int *size,int key)
{
    int pos= searchElement(arr,*size,key);
    if(pos!= -1)
    {
      deletebyPos(arr,size,pos);
      display(arr,*size);
    }
    else
     printf("Key not found...Deletion not possible\n");
}

void getElement(int *arr,int size,int pos)
{
    if(pos>=0 && pos<size)
       {
        printf("Search successful\nElement found in position %d is %d",pos,*(arr+pos));
       }
    else
        {printf("Invalid Position..\n");}
}

void sort(int *arr,int size)
{
    int temp;
   for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
   {
       if(*(arr+i)>*(arr+j))
       {
           temp=*(arr+i);
            *(arr+i)=*(arr+j);
            *(arr+j)=temp;
       }
   }

}

void reverse(int *arr,int size)
{
    int temp;
   for(int i=0;i<size/2;i++)
      {
           temp=*(arr+i);
            *(arr+i)=*(arr+size-i-1);
            *(arr+size-i-1)=temp;
      }
}

void insertbyOrder(int *arr,int *size,int val)
{
     int i;
   for(i=*size-1;*(arr+i)>=val && i>=0;i--)
        *(arr+i+1)=*(arr+i);

        *(arr+i+1)=val;
        *size+=1;
}


int main()
{
    int size,capty,i,pos,val,*ptr,ch,key;

    printf("Enter the capacity and size of an array:");
    scanf("%d %d",&capty,&size);

    ptr=(int *)malloc(capty * sizeof(int));
    printf("Enter the %d elements:\n",size);
    for(int i=0;i<size;i++)
    scanf("%d",(ptr+i));

        while(1)
              {

                printf("\n             ******MENU******");
                printf("\n1. Display array\t2. Insert element by position\t3. Delete element by position\n");
                printf("4. Insert element by key\t5. Delete element by key\t6. Insert by order\n");
                printf("7. Search by key\t8. Search by position\t9. Reverse the contents\n10. Exit\n");
                printf("Enter the choice:");
                scanf("%d",&ch);
              switch(ch)
              {
                
                   case 1:  display(ptr,size);
                  break;
                
                
                   case 2:
                         
                            if(size==capty)
                                printf("Array is full...Elements cannot be inserted\n");
                            else
                           {
                                printf("Enter the position and value to be inserted:\n");
                                scanf("%d %d",&pos,&val);
                                insertbyPos(ptr,&size,pos,val);
                               display(ptr,size);
                            }
                         break;
                
                 case 3:
                
                   if(size==0)
                      printf("Array is empty...\n");
                  else
                    {
                        printf("Enter the position to be deleted:\n");
                        scanf("%d",&pos);
                        deletebyPos(ptr,&size,pos);
                        display(ptr,size);
                    }
                    break;
                

              case 4:
                
                    if(size==0)
                        printf("Array is empty...\n");

                    else
                    {
                       printf("Enter the key value and new value to be replaced:\n");
                        scanf("%d %d",&key,&val);

                        pos= searchElement(ptr,size,key);
                        if(pos!= -1)
                            {
                                *(ptr+pos)=val;
                                display(ptr,size);
                            }
                        else
                            printf("Key not found...Insertion not possible\n");
                    }
                    break;
                

              case 5:
                
                   if(size==capty)
                     printf("Array is empty...\n");

                    else
                    {
                    printf("Enter the key value to be deleted:\n");
                   scanf("%d",&key);
                   deletebykey(ptr,&size,key);
                   display(ptr,size);
                    }
                    break;
                
                
              case 6:
            
              if(size==capty)
                  printf("Array is full...Elements cannot be inserted\n");
              else
              {
                printf("Enter the value to be inserted:");
                scanf("%d",&val);
                sort(ptr,size);
                insertbyOrder(ptr,&size,val);
                display(ptr,size);
              }
                break;
            

              case 7:
                
                    if(size==0)
                    printf("Array is empty...\n");
                    else
                    {
                    printf("Enter the key value to be searched:\n");
                   scanf("%d",&key);
                    pos=searchElement(ptr,size,key);
                    if(pos!= -1)
                      printf("Search successful\nElement found in position %d",pos);
                    else
                      printf("Search unsuccessful...Key not found\n");
                    }
                   break;
                

              case 8:
                
                    if(size==0)
                    printf("Array is empty...\n");
                    else
                   {
                    printf("Enter the position to be searched:\n");
                   scanf("%d",&pos);
                   getElement(ptr,size,pos);
                   }
                  break;
                
                
              case 9:
                if(size==0)
                    printf("Array is empty...\n");
                    else
                   {
                    reverse(ptr,size);
                    display(ptr,size);
                   }
                  break;
            
              case 10:
            
                printf("Terminated from the program\n");
                 return 0;
            

                default:
                printf("Invalid choice...enter the correct choice\n");

              }
}
              
    free(ptr);
    return 0;
}
