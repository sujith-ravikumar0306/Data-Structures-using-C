//Shell sort (an improvised algorithm top of insertion sort)

#include<stdio.h>

/*FUNCTION PROTOTYPES*/
void shellSort(int[],int);

void swap(int*, int*);

void main()
{
    int elements;
    printf("---SHELL SORT---\n");
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

    shellSort(arr,len);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DEFINITIONS*/

void swap(int*x, int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void shellSort(int arr[], int len)
{
    int gap;
    int i,j;
    //the first loop(no. of gaps) determine the no of passes
    for(gap=(len/2);gap>=1;gap/=2)
    {
        //this is to increment the j from mid to end of array
        for(j=gap;j<len;j++)
        {
            //this loop will look for forward as well as backward(i-gap) comparison of gap spaced elements.
            for(i=j-gap;i>=0;i=i-gap)
            {
                if(arr[i+gap]>arr[i])
                {
                    break;
                }
                else
                {
                    swap(&arr[i+gap],&arr[i]);
                }
            }
        }
    }
}
