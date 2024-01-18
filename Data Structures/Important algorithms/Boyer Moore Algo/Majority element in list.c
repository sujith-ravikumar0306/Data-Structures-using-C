//BOYER - MOORE Algorithm
//It is used to find maximum element in list whose occurance is greater than half the size of list

#include<stdio.h>
#include<stdbool.h>

//GLOBAL VARIABLES

//FUNCTION PROTOTYPES

int findCandidate(int [],int);

bool verifyCandidate(int[],int,int);

void main()
{
    int arr[]={2,2,2,2,2,3,3,3,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("\nLength of list= %d",len);

    int candidate=findCandidate(arr,len);
    int res=verifyCandidate(arr,len,candidate);
    printf("\ncandidate= %d", candidate);

    if(res==true)
    {
        printf("\n%d is the major element in list",candidate);
    }
    else
    {
        printf("\nNo majority element found!");
    }
}

//FUNCTION DEFINITIONS

//STEP-1 : find the candidate
int findCandidate(int arr[], int len)
{
    int i=0;
    int votes=0, candidate=-1;

    for(i=0;i<len;i++)
    {
        if(votes==0)
        {
            candidate=arr[i];
            votes++;
        }
        else if(arr[i]==candidate)
        {
            votes++;
        }
        else
        {
            votes--;
        }
    }
    return candidate;
}

//STEP-2: verify the candidate to be maximum in list
bool verifyCandidate(int arr[], int len, int candidate)
{
    int i;
    int counter=0;

    for(i=0;i<len;i++)
    {
        if(arr[i]==candidate)
        {
            counter++;
        }
    }
    if(counter > (len/2))
    {
        return true;
    }

    return false;
}
