//Finding the maximum sum of subarrays using 2 loops(brute force)

#include<stdio.h>

//GLOBAL DECLARATIONS
int len;
int i;

//FUNCTION PROTOTYPES
int maxSum(int []);


void main()
{
    printf("Enter the total no. of elements:");
    scanf("%d",&len);

    int arr[len];
    for(i=0;i<len;i++)
    {
        printf("\nEnter value %d :",i+1);
        scanf("%d",&arr[i]);
    }

    int maximumSum=maxSum(arr);
    printf("\nMaximum sum of subarray= %d",maximumSum);
}

//FUNCTION DECLARATIONS
int maxSum(int arr[])
{
    int j;
    int maxsum=0;
    for(i=0;i<len;i++)
    {
        int sum=0;
        for(j=i;j<len;j++)
        {
            sum+=arr[j];
            if(sum > maxsum)
            {
                maxsum=sum;
            }
        }
    }

    return maxsum;
}
