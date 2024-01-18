//Finding the maximum sum of subarrays using three loops

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
    int j,k;
    int maxsum=0; //Theoretically, the maxsum is initiated to negative infinity.

    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            int sum=0;      //set sum to zero of next iteration
            for(k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(maxsum < sum)
                {
                    maxsum=sum; //update new max
                }
        }
    }

    return maxsum;
}
