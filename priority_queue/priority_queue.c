#include <stdio.h>
#include "../utility/utility.h"
#include <stdlib.h>

#define MAX_INT 2147483647

typedef struct PriorityQueue PriorityQueue;
struct PriorityQueue
{
    unsigned maxSize;
    unsigned currentSize;
    int *elements;
};

void siftDownPriorityQueue(PriorityQueue *p_prioQ, int index)
{
    int maxIndex = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < p_prioQ->currentSize && p_prioQ->elements[leftChildIndex] > p_prioQ->elements[maxIndex])
    {
        maxIndex = leftChildIndex;
    }
    if (rightChildIndex < p_prioQ->currentSize && p_prioQ->elements[rightChildIndex] > p_prioQ->elements[maxIndex])
    {
        maxIndex = rightChildIndex;
    }

    if (maxIndex != index)
    {
        // Swap index element with max index element;
        swap(p_prioQ->elements, index, maxIndex);

        // Call balance function on the remaining subtree.
        siftDownPriorityQueue(p_prioQ, maxIndex);
    }
}

void siftUpPriorityQueue(PriorityQueue *p_prioQ, int index)
{
    int parentIndex = (index - 1) / 2;
    if (index > 0 && p_prioQ->elements[index] >= p_prioQ->elements[parentIndex])
    {
        swap(p_prioQ->elements, index, parentIndex);
        siftUpPriorityQueue(p_prioQ, parentIndex);
    }
}

void insertIntoPriorityQueue(PriorityQueue *p_prioQ, int element)
{
    if (p_prioQ->currentSize + 1 <= p_prioQ->maxSize)
    {
        p_prioQ->elements[p_prioQ->currentSize++] = element;
    }
    siftUpPriorityQueue(p_prioQ, p_prioQ->currentSize - 1);
}

int getTopElement(PriorityQueue *p_prioQ)
{
    return p_prioQ->elements[p_prioQ->currentSize - 1];
}

int popTopElement(PriorityQueue *p_prioQ)
{
    if (p_prioQ->currentSize > 0)
    {
        int element = p_prioQ->elements[0];
        swap(p_prioQ->elements, 0, p_prioQ->currentSize - 1);
        p_prioQ->currentSize--;
        siftDownPriorityQueue(p_prioQ, 0);
        return element;
    }
    return MAX_INT;
}

PriorityQueue *createEmptyPriorityQueue(unsigned maxSize)
{
    PriorityQueue *p_prioQ = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    p_prioQ->maxSize = maxSize;
    p_prioQ->currentSize = 0;
    p_prioQ->elements = (int *)malloc(sizeof(int) * maxSize);
    return p_prioQ;
}

PriorityQueue *createPriorityQueueFromArray(int *array, int arraySize, int maxSize)
{
    // Create an empty priority queue.
    PriorityQueue *p_prioQ = createEmptyPriorityQueue(maxSize);

    // Copy the elements directly from the given array.
    for (int i = 0; i < arraySize; i++)
        p_prioQ->elements[i] = array[i];

    // Set current size of the priority queue to the given array size;
    p_prioQ->currentSize = arraySize;

    // Balance the queue.
    for (int i = p_prioQ->currentSize / 2 - 1; i > -1; i--)
    {
        siftDownPriorityQueue(p_prioQ, i);
    }
    return p_prioQ;
}

int main()
{
    int MAX_SIZE = 100;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(array) / sizeof(int);
    PriorityQueue *p_prioQ = createPriorityQueueFromArray(array, arraySize, MAX_SIZE);
    printIntegerArray(p_prioQ->elements, p_prioQ->currentSize);

    // Basically heap sort.
    while (p_prioQ->currentSize)
    {
        printf("%d ", popTopElement(p_prioQ));
    }

    printf("\n");

    return 0;
}