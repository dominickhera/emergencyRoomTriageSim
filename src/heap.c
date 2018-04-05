#include "heap.h"

Heap *createHeap(size_t initialSize, HEAP_TYPE htype, void (*destroyDataFP)(void *data),void (*printNodeFP)(void *toBePrinted),int (*compareFP)(const void *first, const void *second))
{

    Heap * temp = malloc(sizeof(Heap) * initialSize);
    if(temp == NULL)
    {
        return NULL;
    }

    temp->heapTable = malloc(sizeof(*temp->heapTable) * initialSize);

    for(int i = 0; i < initialSize; i++)
    {
        temp->heapTable[i] = NULL;
    }

    temp->type = htype;
    temp->initialSize = 0;
    temp->maxSize = initialSize;
    temp->destroyDataFP = destroyDataFP;
    temp->printNodeFP = printNodeFP;
    temp->compareFP = compareFP;
    
    return temp;

}

Node *createHeapNode(int priority, void *clientID, void *symptomCode)
{

    Node * temp = malloc(sizeof(Node));
    temp->clientID = malloc(sizeof(clientID));
    temp->symptomCode = malloc(sizeof(symptomCode));
    // printf("3\n");
    if(temp == NULL)
    {
        return NULL;
    }

    temp->priority = priority;
    strcpy(temp->clientID, clientID);
    strcpy(temp->symptomCode, symptomCode);


    return temp;

}

void insertHeapNode(Heap *heap, int priority, void *clientID, void *symptomCode)
{

    if(heap == NULL)
    {
        printf("Heap either does not exist or has been created incorrectly.\n");
        //     return NULL;  
    }
    else
    {

        Node * temp = createHeapNode(priority, clientID, symptomCode);

        int tempSize = heap->initialSize;

        heap->initialSize++;

        while(tempSize && temp->priority > heap->heapTable[getParent(tempSize)]->priority)
        {
            heap->heapTable[tempSize] = heap->heapTable[getParent(tempSize)];
            tempSize = getParent(tempSize);
        }

        heap->heapTable[tempSize] = temp;

        reheapifyMin(heap, 0);


    }

}

void deleteMinOrMax(Heap *heap)
{

    if(heap != NULL)
    {

        Node * minVal = getMinOrMax(heap);
        free(minVal);
        heap->maxSize--;
        reheapifyMin(heap, 0);
        // printf("Max Value successfully deleted\n");
    }
    else
    {
        printf("Heap either does not exist or has been created incorrectly.\n");
    }

}

void *getMinOrMax(Heap *heap)
{
    if(heap != NULL)
    {
        return heap->heapTable[heap->maxSize - 1];
    }
    else
    {
        printf("Heap either does not exist or has been created incorrectly.\n");
        return NULL;
    }
}


void deleteHeap(Heap *heap)
{
    if(heap != NULL)
    {


        while(heap->maxSize != 1)
        {

            deleteMinOrMax(heap);

        }

        heap->maxSize--;
        free(heap->heapTable);
        // printf("Heap has been successfully deleted\n");
    }
    else
    {
        printf("Heap either does not exist or has been created incorrectly.\n");
    }
    // }
}

void reheapifyMin(Heap * heap, int tempSize)
{

// printf("lol\n");
    if(heap != NULL)
    {
        // printf("1\n");
        int tempInt = 0;
        // printf("entering clientID: %s, priority: %d\n", heap->heapTable[tempSize]->clientID, heap->heapTable[tempSize]->priority);
        if(getLeftChild(tempSize) < heap->initialSize && heap->heapTable[getLeftChild(tempSize)]->priority < heap->heapTable[tempSize]->priority)
        {
            // printf("priority: %d, left Priority: %d\n", heap->heapTable[tempSize]->priority, heap->heapTable[getLeftChild(tempSize)]->priority);
            // printf("2\n");
            tempInt = getLeftChild(tempSize);
        }
        else
        {
            // printf("3\n");
            tempInt = tempSize;
        }

        // printf("4\n");

        if(getRightChild(tempSize) < heap->initialSize && heap->heapTable[getRightChild(tempSize)]->priority < heap->heapTable[tempInt]->priority)
        {
            // printf("5\n");
            tempInt = getRightChild(tempSize);
        }

        if(tempInt != tempSize)
        {
            // printf("6\n");
            Node * swapNode = heap->heapTable[tempSize];
            // printf("7\n");
            heap->heapTable[tempSize] = heap->heapTable[tempInt];
            // printf("8\n");
            heap->heapTable[tempInt] = swapNode;
            // printf("9\n");
            reheapifyMin(heap, tempInt);
            // printf("10\n");
        }
        // printf("11\n");
    }
    else
    {
        printf("Heap either does not exist or has been created incorrectly.\n");
    }
}


int getParent(int tempInt)
{

    return ((tempInt - 1)/2);

}

int getLeftChild(int tempInt)
{

    return ((tempInt * 2) + 1);

}

int getRightChild(int tempInt)
{

    return ((tempInt * 2) + 2);

}

void printHeap(Heap * heap, FILE * outputFile, int option)
{
    if(heap != NULL)
    {
        if(option == 1)
        {
            for(int i = 0; i < heap->initialSize; i++)
            {
                if(strcmp(heap->heapTable[i]->symptomCode, "CV") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Cardiovascular, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "HN") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Ears, mouth, throat, nose, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "EV") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Environmental, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "GI") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Gastrointestinal, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "MH") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Mental Health, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "NC") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Neurological, Time to get Processed: %d minutes\n",heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "EC") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Opthalmology, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "RC") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Respiratory, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "SK") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Skin, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "SA") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Substance Abuse, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "TR") == 0)
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Trauma, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else
                {
                    fprintf(outputFile, "ClientID: %s, Priority: %d, Symptom Code: Unknown, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
            }
        }
        else if(option == 2)
        {

            for(int i = 0; i < heap->initialSize; i++)
            {
                if(strcmp(heap->heapTable[i]->symptomCode, "CV") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Cardiovascular, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "HN") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Ears, mouth, throat, nose, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "EV") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Environmental, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "GI") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Gastrointestinal, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "MH") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Mental Health, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "NC") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Neurological, Time to get Processed: %d minutes\n",heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "EC") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Opthalmology, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "RC") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Respiratory, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "SK") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Skin, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "SA") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Substance Abuse, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else if(strcmp(heap->heapTable[i]->symptomCode, "TR") == 0)
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Trauma, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
                else
                {
                    printf("ClientID: %s, Priority: %d, Symptom Code: Unknown, Time to get Processed: %d minutes\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, (i * 30));
                }
            }
        }
        else
        {
            // printf("triggered\n");
            for(int i = 0; i < heap->initialSize; i++)
            {
                if(i + 1 != heap->initialSize)
                {
                    // printf("not last\n");
                    fprintf(outputFile, "%s %d %s\n", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, heap->heapTable[i]->symptomCode);
                }
                else
                {
                    // printf("last\n");
                    fprintf(outputFile, "%s %d %s", heap->heapTable[i]->clientID, heap->heapTable[i]->priority, heap->heapTable[i]->symptomCode);
                }
            }
        }

    }
    else
    {

        printf("Heap either does not exist or has been created incorrectly.\n");
    }
}

void deleteHeapNode(Heap *heap, void *clientID)
{

    for(int i = 0; i < heap->initialSize; i++)
    {
        if(strcmp(heap->heapTable[i]->clientID, clientID) == 0)
        {
            printf("clientID: %s\n", heap->heapTable[i]->clientID);
            free(heap->heapTable[i]);
            heap->initialSize--;
            reheapifyMin(heap, i);
        }
    }
}

