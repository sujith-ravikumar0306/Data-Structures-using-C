//QUICK SORT


/*
#include<stdio.h>

/*GLOBAL DECLARATIONS*/

/*FUNCTION PROTOTYPES*/

/*
void mergeSort(int[], int, int);

void merge(int[], int, int, int);

void main()
{
    printf("---QUICK SORT---\n");
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
    int lb=0,ub=len-1;
    printf("\nlen=%d",len);
    printf("\nub=%d",ub);
    printf("\nlb=%d",lb);

    mergeSort(arr,lb,ub);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DECLARATIONS*/

/*

void mergeSort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[],int lb, int mid, int ub)
{
    int arr2[ub+1];
    int i=lb, j=mid+1, k=lb;
    //validation of left and right subarray
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            arr2[k]=arr[i];
            i++;
        }
        else
        {
            arr2[k]=arr[j];
            j++;
        }
        //update the final array in each case...
        k++;
    }
    // if one sub-array is completely sorted, just copy the remaining element from other array
    if(i>mid)
    {
        while(j<=ub)
        {
            arr2[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            arr2[k]=arr[i];
            i++;
            k++;
        }
    }

    //copy the elements of finalized array to original array
    for(k=0;k<=ub;i++)
    {
        printf("arr2[%d]=",arr2[k]);
    }
}
*/



// The below is an error less code from geeksforgeeks

// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[],
	// if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[],
	// if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m +1, r);

		merge(arr, l, m , r);
	}
}

// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}


