//KMP Algorithm
//String matching algorithm with O(n+m)

#include<stdio.h>
#include<string.h>

//GLOBAL DECLARATIONS


//FUNCTION PROTOTYPES

void generateLPS(char[],int,int*);

void KMPsearch(char *, char *);

void main()
{
    char txt[]="hello mello cello";
    char pat[]="llo";

    KMPsearch(txt,pat);
}

//FUNCTION DECLARATIONS

void generateLPS(char pat[],int m, int *lps)
{
    lps[0]=0;   //first index value is always 0;

    int i=1,j=0;

    while(i<m)
    {
        if(pat[i]==pat[j])
        {
            j+=1;
            lps[i]=j;
            i+=1;
       }
        else if(j>0)
        {
            j=lps[j-1];
        }
        else
        {
            lps[i]=0;
            i+=1;
        }
    }
}

void KMPsearch(char *txt, char *pat)
{
    int m= strlen(pat);
    int n= strlen(txt);

    //array for holding longest prefix/suffix value for pattern
    int lps[m];

    //preprocess the pattern
    generateLPS(pat, m, lps);

    int i=0,j=0;

    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            printf("Pattern found at index %d\n",i-j);
            j=lps[j-1];
        }

        //mismatch after j matches
        else if(i<n && pat[j]!= txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i=i+1;
            }
        }
    }
}
