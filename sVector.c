// Function  Pointer which points the vector function.
typedef struct  sVectorList
{
    void **items;
    int capacity;
    int total;
} sVectorList;

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
}