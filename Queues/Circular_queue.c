#include <stdio.h>
#include <stdlib.h>
#define N 10

// Circular Queue Structure

struct CQ
{
    int* array;
    int front, rear;// capacity;
};

// Function to create a Circular Queue with given capacity

struct CQ* createCircularQueue(int capacity)
{
    struct CQ* queue = (struct CQ*)malloc(sizeof(struct CQ));   //create memory for queue which is a type of the defined structure
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

// Function to add an element to the Circular Queue
void enqueue(struct CQ* queue, int data)
{
    if ((queue->rear + 1) % N == queue->front)
        {
            printf("Circular Queue is full. Cannot enqueue.\n");
            return;
        }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % N;
    queue->array[queue->rear] = data;
}

void display(struct CQ* queue)
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
// Function to remove an element from the Circular Queue
int dequeue(struct CQ* queue) {
    if (queue->front == -1) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % N;
    }
    return data;
}

int main()
{
    int data, choice, element;
    struct CQ* queue = NULL;
    queue = createCircularQueue(N);

    do
    {
        printf("\nChoose.\n");
        printf("1. Enqueue.\n");
        printf("2. Dequeue. \n");
        printf("3. Display\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;

            case 2:
                printf("Dequeued element: %d\n", dequeue(queue));
                break;
            case 3:
                display(queue);
                break;
            case 4:
                break;
            default:
                printf("Invalid.");
                break;

        }
    }while(choice !=4);
    free(queue->array);
    free(queue);

    return 0;
}
