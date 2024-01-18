//1-D Arrays.

/*

//---->// Traversing(visiting all elements exactly once) through one dimention array

#include<stdio.h>
void main(){
    int arr[50],size,i;
    printf("Enter size of array:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
    }

}



//---->//Insertion of elements in  array

#include<stdio.h>

int i;

void insertAtSpecified(int[],int);

void main(){
    int arr[50],size;
    printf("Enter size of array:");
    scanf("%d",&size);
    if(size>50){
        printf("Buffer Overflow!");
    }
    else{
        for(i=0;i<size;i++){
            printf("Enter element %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        for(i=0;i<size;i++){
            printf("\nElement arr[%d]: %d",i,arr[i]);
        }

        insertAtSpecified(arr,size);
    }
}

//1. insert at the specified position
void insertAtSpecified(int arr[],int size){
    int num,pos;
    printf("\nEnter a number to insert:");
    scanf("%d",&num);
    printf("\nEnter the position to insert:");
    scanf("%d",&pos);

    if(pos<=0 || pos>size+1){
        printf("Invalid position!");
    }
    else{
    for(i=size-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;
    for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
    }
    }
}



#include<stdio.h>

void insertAtStart(int [],int);
int i;

void main(){
    int arr[50],size;
    printf("Enter size of array:");
    scanf("%d",&size);
    if(size>50){
        printf("Buffer Overflow!");
    }
    else{
        for(i=0;i<size;i++){
            printf("Enter element %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        for(i=0;i<size;i++){
            printf("\nElement arr[%d]: %d",i,arr[i]);
        }

        insertAtStart(arr,size);
    }
}


//Insertion at starting of the array

void insertAtStart(int arr[],int size){
        int num;
        printf("\nEnter a number to insert in the starting:");
        scanf("%d",&num);
        for(i=size-1;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=num;
        size++;
        for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
        }
}



#include<stdio.h>

void insertAtEnd(int[],int);
int i;
void main(){
    int arr[50],size;
    printf("Enter size of array:");
    scanf("%d",&size);
    if(size>50){
        printf("Buffer Overflow!");
    }
    else{
        for(i=0;i<size;i++){
            printf("Enter element %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        for(i=0;i<size;i++){
            printf("\nElement arr[%d]: %d",i,arr[i]);
        }

        insertAtEnd(arr,size);
    }

}

//insertion at the end of array

void insertAtEnd(int arr[],int size){
        int num;
        printf("\nEnter a number to insert at end:");
        scanf("%d",&num);
        arr[size]=num;
        size++;
        for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
        }
}


//Insertion of element at specified position with time complexity 0(1)-best.
//only possible for unsorted array.

#include<stdio.h>

void main(){
    int i,size, arr[20], num, pos;
    printf("Enter size of array:");
    scanf("%d",&size);
    if(size>20){
        printf("Buffer Overflow!");
    }
    else{
        for(i=0;i<size;i++){
            printf("Enter element %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        for(i=0;i<size;i++){
            printf("\nElement arr[%d]: %d",i,arr[i]);
        }

        printf("\nEnter the element:");
        scanf("%d",&num);
        printf("Enter the position to insert:");
        scanf("%d",&pos);
        if(pos<=0 || pos>size){
            printf("Invalid position!");
        }
        else{
                //just swapping the position to last element
            arr[size]=arr[pos-1];
            arr[pos-1]=num;
            size++;
        }
        for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
        }
    }

}



//---->deletion of elements in an array

#include<stdio.h>

int i;

void delAtSpec(int[],int);

void delAtStart(int[],int);

void delAtEnd(int[],int);

void bestDelAtSpec(int[],int);

void main(){
    int size, arr[20];
    printf("Enter size of array:");
    scanf("%d",&size);
    if(size>20){
        printf("Buffer Overflow!");
    }
    else if(size<=0){
        printf("Invalid size!");
    }
    else{
        for(i=0;i<size;i++){
            printf("Enter element %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        for(i=0;i<size;i++){
            printf("\nElement arr[%d]: %d",i,arr[i]);
        }

        //delAtSpec(arr,size);
        //delAtStart(arr,size);
        //delAtEnd(arr,size);
        bestDelAtSpec(arr,size);
        }
}

//deletion at a specific position.

void delAtSpec(int arr[],int size){
    int pos;
    printf("\nEnter the position to delete:");
        scanf("%d",&pos);
        if(pos<=0 || pos>size){
            printf("Invalid position!");
        }
        else{
        for(i=pos-1;i<size-1;i++){
        arr[i]=arr[i+1];
        }
         size--;
        for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
        }
        }
}

//deletion at starting of array

void delAtStart(int arr[],int size)
{
    for(i=0;i<=size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("\nAfter deletion:-");
    for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
        }
}

//deletion at end of array

void delAtEnd(int arr[],int size)
{
    size--;
    printf("\nAfter deletion at end:-");
    for(i=0;i<size;i++){
         printf("\nElement arr[%d]: %d",i,arr[i]);
    }
}

//Insertion of element at specified position with time complexity 0(1)-best.
//only possible for unsorted array.

void bestDelAtSpec(int arr[],int size){
    int pos;
    printf("\nEnter a position to delete element:");
    scanf("%d",&pos);
    arr[pos-1]=arr[size-1];
    size--;
    for(i=0;i<size;i++){
        printf("\nElement arr[%d]: %d",i,arr[i]);
    }

}




#include<stdio.h>

void main(){
    int a[5]={1,2,3,4,5},*p,i;
    p=&a;
    printf("a=%d",&a);
    printf("*p=%d",&p);

    printf("a=%d",&a[i]);
    printf("*p=%d",&p[i]);

    printf("Enter elements:");
    for(i=0;i<5;i++){
             scanf("\n%d",&p[i]);
          }

            for(i=0;i<5;i++){
             printf("\n%d",*(p+i));
          }

}



//-------------------------
//      2-D Arrays
//-------------------------

#include<stdio.h>
void main(){
    int arr[3][3],i,j;
    int row,col,address;

    printf("Enter row size:");
    scanf("%d",&row);
    printf("\nEnter coloum size:");
    scanf("%d",&col);

    if((row<=0 || col<=0) ||  (row>3 || col>3)){
        printf("The row-coloum size must be between 1-3!");
    }
    else{
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\nEnter arr[%d][%d] :",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nEntered array:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    printf("\nArray addresses:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",&arr[i][j]);
        }
        printf("\n");
    }

    printf("\nAddress of a[1][1]:\n");
    address=arr+((1*3)+1)*sizeof(int);
    printf("%d",address);
    }
}



// pointers and 2-D arrays

#include<stdio.h>

void main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int**p=&a;
    printf("%d",*(*a+1));
    printf("\n%d",**a);
    printf("\n%d",*(*p));
}

*/
#include<stdio.h>

void main(){
    int a[3]={1,2,3},*p;
    p=&a;
    printf("%d",a[1]);
    printf("\n%d",&p);
    printf("\n%d",&a);
    printf("\n%d",p[1]);
}
