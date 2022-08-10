/// ILOPOISI OURAS ME KIKLIKO PINAKA...
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear;
    int size; // posa stixia ezi i oura ekini tin stigmi...
    int capacity; // auto einai gia tin desmeusi tou pinaka...
    int *array;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;

    queue->size = 0;

    queue->front = 0;
    queue->rear = 0;

    queue->array = (int*)malloc(sizeof(int) * capacity);

    return queue;
}


/// auti tha douleue mono an legame oti to front kai to rear einai arxika 0 kai t adio...
int isEmpty(struct Queue *q)
{
    if(q->size == 0)
    {
        printf("The Queue is Empty...\n");
        return 0;
    }
    else
    {
        printf("The Queue is not Empty...\n");
        return 1;  
    }
}

/// SOS AUTO (GIA BOITHIS DES TO PDF LAB SEL 9-10)
int isFull(struct Queue *q)
{
    if((q->front == 0 && q->rear == q->capacity - 1) ||
			(q->rear == (q->front - 1) % (q->capacity)))
    {
        printf("The Queue is Full...\n");
        return 0;
    }
    else
    {
        printf("The Queue is not Full...\n");
        return 1;
    }
}

void enqueue(struct Queue *q, int dataInserted)
{
    if(isFull(q) == 0)
    {
        return;
    }
    else
    {
        /// an den exoume ena stixio stin oura, tote prepi na dmiourgisoume zexoristi periptosi
        if(q->front == 0 && q->rear == 0 && q->size == 0)
        {
            q->array[q->rear] = dataInserted;
            q->size++;
            printf("TEST rear proti fora --> %d\n", q->rear);
            return;
        }

        /// an to rear ftasi sto telos tote simaini oti prepi na to pami stin arxi...
        if(q->rear == q->capacity - 1 && q->front != 0)
        {
            q->rear = 0;
            q->array[q->rear] = dataInserted;
            q->size++;
            printf("TEST rear otan ftasi sto telos --> %d\n", q->rear);
            return;
        }

        q->rear = (q->rear + 1) % q->capacity;
        q->array[q->rear] = dataInserted;
        printf("TEST rear OXI proti fora --> %d\n", q->rear);
        q->size++;

        return;
    }
}

void dequeue(struct Queue *q)
{
    if(isEmpty(q) == 0)
    {
        return;
    }
    else
    {
        int temp = q->array[q->front]; // giati auto pou einai stin arxi feugi...
        q->array[q->front] = -99; // kai kala san na kanis free...

        /// an exoume ena stixio stin oura, tote prepi na dmiourgisoume zexoristi periptosi
        if(q->front == 0 && q->rear == 0 && q->size == 1)
        {
            q->size = 0;
            printf("TEST FRONT MESA APO TIN IF ARXIKI --> %d\n", q->front);
            printf("Value dequeued is --> %d", temp);
            return;
        }

        /// an to front ftasi sto telos tote prepi na to pame stin arxi...
        if(q->front == q->capacity - 1)
        {
            q->front = 0;
            q->size--;
            printf("TEST FRONT EZO APO TIN IF ARXIKI --> %d\n", q->front);
            printf("Value dequeued is --> %d\n", temp);
            return;
        }

        q->front = (q->front + 1) % q->capacity;
        q->size--;
        printf("TEST FRONT EZO APO TIN IF ARXIKI --> %d\n", q->front);
        printf("Value dequeued is --> %d\n", temp);

        return;
    }
}

int main()
{
    struct Queue *queue = createQueue(3);
    
    printf("ARXIKA\n");
    isEmpty(queue);
    isFull(queue);

    printf("\nMETA TO 45\n");
    enqueue(queue, 45);
    isEmpty(queue);
    
    isFull(queue);

    printf("\nMETA TO 898\n");
    enqueue(queue, 898);
    isEmpty(queue);

    isFull(queue);

    printf("\nMETA TO DEQUEUE\n");
    dequeue(queue);
    isEmpty(queue);

    isFull(queue);

    printf("\nMETA TO 12\n");
    enqueue(queue, 12);
    isEmpty(queue);

    isFull(queue);

    printf("\nMETA TO 666\n");
    enqueue(queue, 666);
    isEmpty(queue);

    isFull(queue);
return 69;	

}
