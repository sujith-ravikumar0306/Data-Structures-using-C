//Optimized code for bubble sort algorithm;
//flag variable will control unnecessary passes;
//(j<n-1-i) will control the unnecessary passes;

#include<stdio.h>

/*GLOBAL DECLARATIONS*/

int elements;

/*FUNCTION PROTOTYPES*/
void bubbleSort(int [elements],int);

void main()
{
    printf("---BUBBLE SORT---\n");
    int i;
    printf("Enter the total elements in array:");
    scanf("%d",&elements);

    int arr[elements];
    for(i=0;i<elements;i++)
    {
        printf("\nEnter element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    int len=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,len);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }

}


/*FUNCTION DEFINITIONS*/

bubbleSort(int arr[elements],int len)
{
    int i,j;
    int temp,flag;

    //this loop is to control the no. of passes
    for(i=0;i<len-1;i++)
    {
        flag=0;
        //this loop is to control the no. of swaps
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                //update flag if swaps are done
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }

}
