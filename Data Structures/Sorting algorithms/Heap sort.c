//HEAP SORT

//the code works until heapify method for array to max heap, deletion is not proper.

/*
#include<stdio.h>

/*GLOBAL DECLARATIONS*/

/*FUNCTION PROTOTYPES*//*
void heapSort(int[], int);

void heapify(int[], int, int);

void swap(int*,int*);

void main()
{
    printf("---HEAP SORT---\n");
    int elements;
    int i;
    printf("Enter the total elements in array:");
    scanf("%d",&elements);

    int arr[elements];
    for(i=0;i<elements;i++)
    {
        printf("\nEnter element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    int len=elements;
    heapSort(arr,len);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DECLARATIONS*//*

void heapSort(int arr[],int len)
{
    for(int i=len/2-1;i>=0;i--)
    {
        heapify(arr,len,i);
    }
    for(int i=len-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,len,0);
    }

}


void heapify(int arr[],int len,int i)
{
    int temp;
    int largest=i;
    int left=(2*i)+1;
    int right= (2*i)+2;

    while(left<len && arr[left]>arr[largest])
    {
        largest=left;
        printf("\nleft=%d",left);
    }
    while(right<len && arr[right]>arr[largest])
    {
        largest=right;
        printf("\nright=%d",right);
    }
    if(largest!=i)
    {
        printf("\nlargest=%d",largest);
        swap(&arr[i],&arr[largest]);
        heapify(arr,len,largest);
    }
}

void swap(int *x,int *y)
{
    int temp= *x;
    *x= *y;
    *y= temp;
}

*/


/* code from geeksforgeeks*/

// Heap Sort in C

#include <stdio.h>

// Function to swap the position of two elements

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // Heapify root element
        // to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver's code
int main()
{
    int arr[] = { 234, 325, 325425, 32432, 34432, 2343};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}




