#include<stdio.h>
#include<stdlib.h>
#define N 10

// Priority Queue Structure
struct PQ
{
    int* array;
    int front, rear;
};

// Function to create a Priority Queue
struct PQ* createPriorityQueue()
{
    struct PQ* queue = (struct PQ*)malloc(sizeof(struct PQ));   //creating queue which is of type struct
    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    queue->array = (int*)malloc(N * sizeof(int));           //crating an array
    if (queue->array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    queue->front = queue->rear = -1;
    return queue;
}

// Function to enqueue an element with priority (using design 2)
//enqueue in a sorted manner, and dequeue normally
void enqueue(struct PQ* queue, int data)
{
    if (queue->rear == N - 1)
    {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    int i;
    if (queue->front == -1) // Queue is empty
    {
        queue->front = queue->rear = 0;
        queue->array[queue->rear] = data;
    }
    else
    {
        for (i = queue->rear; i >= 0; i--)      //start from the rear pointer
        {
            if (data < queue->array[i])         //if the inserted element is lesser than the array element, it will move the position by 1, and insert the element there
                queue->array[i + 1] = queue->array[i];
            else
                break;      //else proceed for the next iteration
        }
        queue->array[i + 1] = data;     //as soon as space is created for that element, the loop breaks and the data(inserted element) is inserted.
        queue->rear++;                  //increment the rear because one new element is added
    }
}


//Normal Dequeue operation
int dequeue(struct PQ* queue)
{
    if (queue->front == -1)
    {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return data;
}


void display(struct PQ* queue)
{
    if (queue->front == -1)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main()
{
    int choice, element;
    struct PQ* queue = createPriorityQueue();

    do
    {
        printf("\nChoose:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to enqueue: ");
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
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    free(queue->array);
    free(queue);

    return 0;
}
