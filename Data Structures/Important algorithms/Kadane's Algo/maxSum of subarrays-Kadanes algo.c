//KADANE'S ALGO- largest sum contiguous sub-array

#include<stdio.h>

//GLOBAL DECLARATIONS
int i,j;

//FUNCTION PROTOTYPES
int maxSumSubarray(int [], int);

void main()
{
    int elements;
    printf("Enter the total elements in array:");
    scanf("%d",&elements);
    int arr[elements];
    for(i=0;i<elements;i++)
    {
        printf("\nEnter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    int maxSum=maxSumSubarray(arr,elements);
    printf("\nThe maximum sum of subarray = %d",maxSum);
}

//FUNCTION DECLARATIONS

int maxSumSubarray(int arr[],int len)
{
    int max_so_far=0;
    int max_end_here=0;

    for(i=0;i<len;i++)
    {
        max_end_here=max_end_here+arr[i];

        if(max_so_far < max_end_here)
        {
            max_so_far = max_end_here;
        }
        if(max_end_here < 0)
        {
            max_end_here=0;
        }
    }

    return max_so_far;
}
