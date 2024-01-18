//RADIX SORT/ BUCKET SORT (sorting without comparison for long range elements)
/*
#include<stdio.h>

//GLOBAL VARIABLES
int elements;

//FUNCTION PROTOTYPES
int getMax(int []);

void radixSort(int[], int);

void countSort(int[], int ,int);


void main()
{
    printf("---RADIX SORT---\n\n");

    printf("Enter total no. of elements:");
    scanf("%d",&elements);

    int arr[elements];
    int i;
    for(i=0;i<elements;i++)
    {
        printf("\nEnter element %d :",i+1);
        scanf("%d",&arr[i]);
    }

    radixSort(arr,elements  );

    printf("\nSorted list:\n");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}



//FUNCTION DECLARATIONS

int getMax(int arr[])
{
    int i;
    int max_element=0;
    int digit_count=1;

    for(i=0;i<elements;i++)
    {
        if(arr[i]>max_element)
        {
            max_element=arr[i];
        }
    }

     return max_element;
}

void radixSort(int arr[], int elements)
{
    int pos;
    int max=getMax(arr);
    printf("%d--",max);
    for(pos=1;(max/pos)>0;pos++)
    {
        countSort(arr,elements,pos);
        pos*=10;
    }

}

void countSort(int arr[],int elements, int pos)
{
    int b[elements];
    int i;
    int count[10];
    for(i=0;i<10;i++)
    {
        count[i]=0;
    }

    for(i=0;i<elements;i++)
    {
        ++count[(arr[i]/pos)%10];
    }

    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    for(i=elements-1;i>0;i--)
    {
        b[--count[(arr[i]/pos)%10]]=arr[i];
    }

    for(i=0;i<elements;i++)
    {
        arr[i]=b[i];
    }
}
*/

// Radix Sort in C Programming

#include <stdio.h>

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}



/*Code from Programiz*/

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
     printf("---RADIX SORT---\n\n");
  int array[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);
}
