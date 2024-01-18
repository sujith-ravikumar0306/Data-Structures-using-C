//COUNTING SORT (an algorithm for sorting without comparison and sorts)

#include<stdio.h>

/*FUNCTION PROTOTYPES*/
void countingSort(int[],int,int);

void main()
{
    int elements;
    int len=elements;
    int i;
    int max=0;
    printf("---COUNTING SORT---\n");
    printf("Enter the total elements in array:");
    scanf("%d",&elements);

    int arr[elements];
    for(i=0;i<elements;i++)
    {
        printf("\nEnter element %d:",i+1);
        scanf("%d",&arr[i]);

        //find the maximum element in array to use in sorting function
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }


    countingSort(arr,len,max);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DEFINITIONS*/

void countingSort(int arr[],int len,int max)
{
    int i;
    int sorted[len];
    int count[max];
    //initialize count to zero
    for(i=0;i<=max;i++)
    {
        count[i]=0;
    }
    //loop for counting the number of elements and storing them in count array
    for(i=0;i<=max;i++)
    {
        ++count[arr[i]];
        printf("\nloop-2");
        printf("\ncount-%d=%d",i,count[i]);
    }
    //for loop to obtain the cumulative frequency
    for(i=1;1<max;i++)
    {
        count[i] = count[i]+count[i-1];
        printf("\nloop-3");
        printf("\ncount-%d 2=%d",i,count[i]);
    }
    //loop to create an sorted array
    //sorted from left to right to maintain stability
    for(i=len-1;i>=0;i--)
    {
        sorted[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
        printf("\nloop-4");
    }
    //loop for copying sorted array to original array
    for(i=0;i<len;i++)
    {
        arr[i]=sorted[i];
        printf("\nloop-5");
    }
}

/*PROGRAM FROM PROGRAMIZ*/
/*
#include <stdio.h>

void countingSort(int array[], int size) {
  int output[10];

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[10];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countingSort(array, n);
  printArray(array, n);
}

*/
