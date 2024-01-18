//EUCLEDIAN ALGORITHM
//This algorithm is used to find GCD of two numbers using recursion

#include<stdio.h>

//GLOBAL DECLARATIONS

//FUNCTION PROTOTYPES
int find_gcd(int, int);

void main()
{
    int n1,n2;
    printf("Enter two numbers to find their gcd:");
    scanf("%d%d",&n1,&n2);

    printf("The gcd of %d and %d is : %d", n1, n2, find_gcd(n1,n2));
}

//FUNCTION DEFINITIONS

int find_gcd(int a, int b)
{
    if(a==0)
        return b;
    return find_gcd(b%a,a);
}
