#include<stdio.h>
#include<stdlib.h>
#define N 10
// Doubly Ended Queue Structure

struct DQ
{
    int* array;
    int front, rear;// capacity;
};

// Function to create a Circular Queue with given capacity

struct DQ* createDeque()
{
    struct DQ* queue = (struct DQ*)malloc(sizeof(struct DQ));   //create memory for queue which is a type of the defined structure
    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    //queue->capacity = capacity;
    queue->array = (int*)malloc(N * sizeof(int));     //using the above defined queue to access array of the structure and allocate memory
    if (queue->array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    queue->front = queue->rear = -1;
    return queue;
}

void enqueueFront(struct DQ* queue, int data)
{
    if ((queue->front == 0 && queue->rear == N - 1) || (queue->rear == (queue->front - 1) % N))
    {
        printf("Deque is full. Cannot enqueue.\n");
        return;
    }
    else if (queue->front == -1 && queue->rear == -1) //for inserting the first element.
    {
        queue->front = 0;
        queue->rear = 0;
        queue->array[queue->front] = data;
    }
    else if (queue->front == 0) //for the queue to move in a circular fashion
    {
        queue->front = N - 1;
        queue->array[queue->front] = data;
    }
    else // for remaining nodes/data
    {
        queue->front--;
        queue->array[queue->front] = data;
    }
}

void enqueueRear(struct DQ* queue, int data)
{
    if ((queue->front == 0 && queue->rear == N - 1) || (queue->rear == (queue->front - 1) % N))
    {
        printf("Deque is full. Cannot enqueue.\n");
        return;
    }
    else if (queue->front == -1 && queue->rear == -1) //for inserting the first element.
    {
        queue->front = 0;
        queue->rear = 0;
        queue->array[queue->rear] = data;
    }
    else if (queue->rear == N - 1) //for the queue to move in a circular fashion
    {
        queue->rear = 0;
        queue->array[queue->rear] = data;
    }
    else // for remaining nodes/data
    {
        queue->rear++;
        queue->array[queue->rear] = data;
    }
}

void display(struct DQ* queue)
{
    if(queue->front==-1 && queue->rear==-1)
    {
        printf("Empty Queue.");
        return;
    }
    else
    {
        printf("The Queue is: ");
        int i=queue->front;
        while(i!=queue->rear)
        {
            printf("%d ",queue->array[i] );
            i=(i+1)%N;
        }
        printf("%d", queue->array[i]);
    }

}

void dequeueFront(struct DQ* queue)
{
    if(queue->front ==-1 && queue->rear==-1)
    {
        printf("Empty Queue. Cannot Dequeue.");
        return;
    }
    else if (queue->front==queue->rear)
    {
        printf("The Dequeued Element from the front is %d\n", queue->array[queue->front]);
        queue->front=-1;
        queue->rear=-1;
    }
    else if(queue->front==N-1)
    {
        printf("Dequeued Element is %d \n", queue->array[queue->front]);
        queue->front=0;
    }
    else
    {
       printf("Dequeued Element is %d \n", queue->array[queue->front]);
       queue->front++;
    }

}

void dequeueRear(struct DQ* queue)
{
    if(queue->front ==-1 && queue->rear==-1)
    {
        printf("Empty Queue. Cannot Dequeue.");
        return;
    }
    else if (queue->front==queue->rear)
    {
        printf("The Dequeued Element from the front is %d\n", queue->array[queue->rear]);
        queue->front=-1;
        queue->rear=-1;
    }
    else if(queue->rear==0)
    {
        printf("Dequeued Element is %d \n", queue->array[queue->rear]);
        queue->rear=N-1;
    }
    else
    {
       printf("Dequeued Element is %d \n", queue->array[queue->rear]);
       queue->rear--;
    }

}

int main()
{
    int data, choice, element;
    struct DQ* queue = NULL;
    queue = createDeque(N);
    do
    {
        printf("\nChoose.\n");
        printf("1. Enqueue Front.\n");
        printf("2. Enqueue Rear. \n");
        printf("3. Display\n");
        printf("4. Dequeue Front. \n");
        printf("5. Dequeue Rear. \n");
        printf("6. Exit.\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &element);
                enqueueFront(queue, element);
                break;

            case 2:
                printf("Enter Element: ");
                scanf("%d", &element);
                enqueueRear(queue, element);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                dequeueFront(queue);
                break;
            case 5:
                dequeueRear(queue);
                break;
            case 6:
                break;
             default:
                printf("Invalid.");
                break;

        }
    }while(choice != 6);
    free(queue->array);
    free(queue);

    return 0;
}
