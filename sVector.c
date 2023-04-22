#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE  -1
#define SUCCESS 0

// Define "VECTOR_INIT(vec)" as a initialization for a vector.
#define VECTOR_INIT(vec) vector vec;\
 vector_init(&vec)

// Data storing and tracking.
typedef struct  sVectorList
{
    void **items;
    int capacity;
    int total;
} sVectorList;

// Abbreviate type named "struct sVector" as "vector".
typedef struct sVector vector;
struct sVector
{
    sVectorList vectorList;

    // function pointers
    int (*pfVectorTotal) (vector *);
    int (*pfVectorResize) (vector *, int);
    int (*pfVectorAdd) (vector *, void *);
    int (*pfVectorSet) (vector *, int, void *);
    void *(*pfVectorGet) (vector *, int);
    int (*pfVectorDelete) (vector *, int);
    int (*pfVectorFree) (vector *);
};

int vectorTotal(vector *v)
{
    int totalCount = UNDEFINE;
    if(v)
    {
        totalCount = v->vectorList.total;
    }
    return totalCount;
}

int vectorResize(vector *v, int capacity)
{
    int  status = UNDEFINE;
    if(v)
    {
        void **items = realloc(v->vectorList.items, sizeof(void *) * capacity);
        if (items)
        {
            v->vectorList.items = items;
            v->vectorList.capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorSet(vector *v, int index, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            v->vectorList.items[index] = item;
            status = SUCCESS;
        }
    }
    return status;
}

void *vectorGet(vector *v, int index)
{
    void *readData = NULL;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            readData = v->vectorList.items[index];
        }
    }
    return readData;
}

int vectorPushBack(vector *v, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if (v->vectorList.capacity == v->vectorList.total)
        {
            status = vectorResize(v, v->vectorList.capacity * 2);
            if(status != UNDEFINE)
            {
                v->vectorList.items[v->vectorList.total++] = item;
            }
        }
        else
        {
            v->vectorList.items[v->vectorList.total++] = item;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorPushFront(vector *v, void *item)
{
    int status = UNDEFINE;
    if(v)
    {
        if (v->vectorList.capacity == v->vectorList.total)
        {
            status = vectorResize(v, v->vectorList.capacity *2);
            if (status != UNDEFINE)
            {
                status = UNDEFINE;
                void *temp1 = item;
                void *temp2;
                int MAX = v->vectorList.total + 1;
                for (int i = 0; i < MAX; i++){
                    if(i != v->vectorList.total){
                        temp2 = (char *)vectorGet(v, i);
                        v->vectorList.items[i] = temp1;
                        temp1 = temp2;
                    }else{
                        v->vectorList.items[v->vectorList.total++] = temp1;
                        status = SUCCESS;
                    }
                }
            }
        }
        else
        {
            void *temp1 = item;
            void *temp2;
            int MAX = v->vectorList.total + 1;
            for (int i = 0; i < MAX; i++){
                if(i != v->vectorList.total){
                    temp2 = (char *)vectorGet(v, i);
                    v->vectorList.items[i] = temp1;
                    temp1 = temp2;
                }else{
                    v->vectorList.items[v->vectorList.total++] = temp1;
                    status = SUCCESS;
                }
            }
        }
    }
    return status;
}

int vectorDelete(vector *v, int index)
{
    int  status = UNDEFINE;
    int i = 0;
    if(v)
    {
        if ((index < 0) || (index >= v->vectorList.total))
            return status;
        v->vectorList.items[index] = NULL;
        for (i = index; (i < v->vectorList.total - 1); ++i)
        {
            v->vectorList.items[i] = v->vectorList.items[i + 1];
            v->vectorList.items[i + 1] = NULL;
        }
        v->vectorList.total--;
        if ((v->vectorList.total > 0) && ((v->vectorList.total) == (v->vectorList.capacity / 4)))
        {
            vectorResize(v, v->vectorList.capacity / 2);
        }
        status = SUCCESS;
    }
    return status;
}

int vectorFree(vector *v)
{
    int  status = UNDEFINE;
    if(v)
    {
        free(v->vectorList.items);
        v->vectorList.items = NULL;
        status = SUCCESS;
    }
    return status;
}

void vector_init(vector *v)
{
    // Initialize function pointers
    v->pfVectorTotal = vectorTotal;
    v->pfVectorResize = vectorResize;
    v->pfVectorAdd = vectorPushBack;
    v->pfVectorSet = vectorSet;
    v->pfVectorGet = vectorGet;
    v->pfVectorFree = vectorFree;
    v->pfVectorDelete = vectorDelete;
    
    // Initialize the capacity and allocate the memory
    v->vectorList.capacity = VECTOR_INIT_CAPACITY;
    v->vectorList.total = 0;
    v->vectorList.items = malloc(sizeof(void *) * v->vectorList.capacity);
}

vector solve(vector v)
{
    // TODO@JiseungHong
    // Implement solve algorithm function in vector struct.
    return v;
}

int main(int argc, char* argv[])
{
    // Dimension of the POLYNOMIAL is n.
    int n = argc-1;
    
    // v is a vector which consists of the coefficients.
    VECTOR_INIT(v);
    for (int i = 0; i < n; i++){
        if(vectorPushFront(&v, argv[i+1]) != SUCCESS){printf("ARGUMENT ERROR"); return -1;}
    }

    vector ret = solve(v);
    for (int i = 0; i < vectorTotal(&ret); i++){
        printf("%s ", (char *)vectorGet(&ret, i));
    }
}