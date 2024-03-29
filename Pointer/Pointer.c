#include<stdio.h>
#include<stdlib.h>


// Prototype:
// data_type * pointer_variable_name;     // Data type will be the type of variable the pointer will be pointing to


// Properties :
// Size of all types of pointer is 4/8 bytes(32/64 bit).
// Pointer stores address of variable , not the value . Pointer gives indirect access to variables .
// Pass by reference with the help of pointer


// Types :
// Null Pointer -> int *Ptr = NULL ;
// Void Pointer -> void *Ptr = NULL ;  // Generic Pointer
// Wild Pointer -> int *Ptr;   // Uninitialized Pointer
// Uninitialized should not be dereferenced .


// * -> Dereference Operator -> Unary Operator  // Value of variable the pointer is pointing to can be changed by *
// Void pointer can't be dereferenced .


// int *Ptr;
// &Ptr -> Address of the pointer .
// Ptr -> Address of the variable ,which the pointer is pointing to .
// *Ptr ->  Value of the variable ,which the pointer is pointing to .



// Types of Declaration :
// void *ptr;  // Void pointer (Universal Pointer)
// char *ptr;  // Pointer to character
// int *ptr;  // Pointer to integer
// int *const ptr;  // Constant pointer to integer
// int *ptr[5];  // Array of 5 integer pointer
// int *(ptr[5]); // Array of 5 integer pointer
// int (*ptr)[5];  // Pointer to an array of 5 integer
// int (*ptr)(int,int);  // Function Pointer where the function is --- int Func(int a,int b);
// int *ptr(int,int);  // A function declaration


int* Func()
{

}
int main()
{

    int V = 10;

    int* A, B; // int *A  int *B;
    int *C = NULL ; // null pointer .   // #define NULL ((void*)0)

    // Assignment :
    A = &B;    // Points to a old address
    A = (int*)malloc(sizeof(*A));    // Points to a new address

    int Arr[10];
    A = Arr;    // Points to the first element of an array
    A = (int*)malloc(sizeof(*A) * 10);  // 1D array declaration using pointer.


    char *S = "Dihan";  // Stores the address of a read only location



    A = &V;
    // Arithmetic:
    // / , * , % -> Not Applicable
    // A = A * 2 , A = A / 2 , A = A % 2 ; // Invalid

    // We can add or substract integers from pointer . The result will remain a pointer.
    A--; --A;
    A = A - 1;
    A++; ++A;
    A = A + 1;

    // If we add a 1 to Pointer . The address of that pointer will increase by the sizeof variable it is pointing to . If we add n to Ptr ,
    //it will become Ptr+n*sizeof(*Ptr) .

    /* Above expression is equivalent to - */ A = (void*)A + sizeof(*A) * 1;

    // Two pointers can't be added . One pointer can be substracted from another . The result will be a Long Integer value , not a pointer ;

    // A=A+C; // Invalid

    B = A - C;
    A = A - C + A; //  A = A + ( A - C );  // Valid

 // But an integer  maybe  added to apointer(+ or +=)

    
// Note : Pointers contain addresses. Adding two addresses makes no sense, because there is no idea what it would point to.
//  Subtracting two addresses lets you compute the offset between these two addresses.


    int a[5];
    int *b = a; // Pointer to first element of a 1D array
    int c[5][5];
    int (*d)[5] = c;  // Pointer to first 1D array of a 2D array







    /**************Changing the value of constant variable*************/
    const int Q = 10;
    int *P = (int*) &Q; //without (int*)it will show a error but it will still give output
    *P = 8;
    printf("%u\n", Q);
 

  
    /********************************************************************************************************************/
}

//  int x=10;
//  int *a=x;
//  printf("%d",a);//10


//  int x=10;
//  int *a=&x;
//  printf("%d",*a);//10;

//  int x=10;
//  int *a=&x;
//  printf("%d",a);//memory location//which is equal &a;








//    int n,*a,i;

//   a;//address of first element of array(&x[0]);

//      &a;/*address of pointer a;(no use)*/ a!=&a;

// #    2D Array                                       1D Array

//     int x[n][n];                                    int x[n];


//     a=x[0];                                         a=x;
//     a=&x[0][0];                                     a=&x[0];



// &x+i = x+i = *(x+i) = &x[i] = x[i] = &x[i][0];

// x[i]+1=&x[i][1];                                    x+1=&x[1];

// &x[i]+1=&x[i+1][0];                                 &x+1=&x[n];




// Address of 1st ele:  &x[0][0];                      &x[0];
//                      x[0];                          x;
//                      &x[0];                         &x;
//                      *x;                            &0[x];
//                      x;
//                      &x;





// Address of element:  &x[i][j];                      &x[i];
//                      *(x+i)+j;                      x+i;
//                      x[i]+j;                        &i[x];




//      Array element:  x[i][j];                       x[i];
//                      *(*(x+i)+j);                   *(x+i);
//                      *(x[i]+j)                      i[x];


// int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };

// In general, nums[i][j] is equivalent to *(*(nums+i)+j)



// Pointer Notation       Array Notation    Value
// *(*nums)               nums[0][0]         16
// *(*nums + 1)           nums[0][1]         18
// *(*nums + 2)           nums[0][2]         20
// *(*(nums + 1))         nums[1][0]         25
// *(*(nums + 1) + 1)     nums[1][1]         26
// *(*(nums + 1) + 2)     nums[1][2]         27



// Suppose x is a two-dimensional integer array having 10 rows and 20 columns. We can declare x as
// int (*x)[20];
// rather than
// int x[10][20];
// In the first declaration, x is defined to be a pointer to a group of contiguous, one-dimensional, 20-element integer arrays.
// Thus, x points to the first 20-element array, which is actually the first row (i.e., row 0) of the original two-dimensional
// array. Similarly, ( x + 1) points to the second 20-element array, which is the second row (row 1) of the original twodimensional
// array,

//##------------------------------Poimter & Function-------------------------------------##

//passing address to functions:
 void swap(int *p,int *q);
int main()
{
    int x=10,y=20;
    swap(&x,&y);
    printf("%d %d",x,y);
}
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;

}


//passing pointers to a function:

void go(int* ptr)
{
    (*ptr)++;

}

int main()
{
    int x=10;
    int *p;
    p=&x;//valid
    //int *p=&x//will not work
    go(p);
    printf("%d",*p);
    return 0;
}
//##------------------------------------------------------------------------------##
  /*******************************************************************************************************************/

    //### p is a pointer to a 3 element array of pointers to functions returning a pointer to int

    // Dividing into sub problems

    // p is a pointer to a
    // 3 element array of pointers to
    // functions returning
    // a pointer to
    // int


    // Bottom Up approach

    int Var;   // Integer

    int *p3 ;  // A pointer to integer
    p3 = &Var;  // Check


    int* (*p2)();   // Pointer to a function returning a pointer to int
    p2 = Func;    // Check


    int* (*p1[3])();   // 3 element array of pointers to functions returning a pointer to int
    p1[0] = p2;    // Check


    // int (*Arr)[3];   // Pointer to an array .


    int*(*(*p)[3])();    // p is a pointer to a 3 element array of pointers to functions returning a pointer to int
    p = &p1;   // Check










int *p; /* p i s a pointer t o an integer  q u a n t i t y */

i n t *p[lO]; /* p i s a 10-element array of pointers t o integer q u a n t i t i e s */

i n t (*p) [ 10]; /* p i s a pointer t o a 10-element i n t e g e r a r r a y */

 i n t *p (void) ; /* p i s a function that
returns a pointer t o an i n t e g e r q u a n t i t y */
            

i n t p(char *a); /* p i s a function t h a t
accepts an argument which i s a pointer t o a character and
returns an i n t e g e r q u a n t i t y */
            
i n t *p(char a*); /* p i s a function t h a t
accepts an argument which i s a pointer t o a character
returns a pointer t o an i n t e g e r q u a n t i t y */
            
i n t (*p)(char *a); /* p i s a pointer t o a function t h a t
accepts an argument which is a pointer t o a character
returns an i n t e g e r q u a n t i t y */
            
i n t (*p(char * a ) ) [ l O ] ; /* p i s a function t h a t
accepts an argument which i s a pointer t o a character
returns a pointer t o a 10-element i n t e g e r a r r a y */
            
i n t p(char ( * a ) [ ] ) ; /* p i s a function t h a t
accepts an argument which i s a pointer t o a character array
returns an i n t e g e r q u a n t i t y */
            
i n t p(char * a [ ] ) ; /* p i s a function t h a t
accepts an argument which i s an array of pointers t o
characters
returns an i n t e g e r q u a n t i t y */
            
i n t *p(char a [ ] ) ; /* p i s a function t h a t
accepts an argument which i s a character array
returns a pointer t o an i n t e g e r q u a n t i t y */
            
i n t *p(char ( * a ) [ ] ) ; /* p i s a function t h a t
accepts an argument which i s a pointer t o a character array
returns a pointer t o an i n t e g e r q u a n t i t y */
            
i n t *p(char * a [ ] ) ; /* p i s a function t h a t accepts an argument which i s an array of pointers t o
characters
returns a pointer t o an i n t e g e r q u a n t i t y */
            
            
i n t (*p)(char ( * a ) [ ] ) ; /* p i s a pointer t o a function t h a t
accepts an argument which i s a pointer t o a character array
returns an i n t e g e r q u a n t i t y */
            
i n t *(*p)(char ( * a ) [ ] ) ; /* p i s pointer t o a function t h a t
accepts an argument which i s a pointer t o a character array
returns a pointer t o an integer q u a n t i t y */
            
i n t *(*p)(char * a [ ] ) ; /* p i s a pointer t o a function t h a t
accepts an argument which i s an array of pointers t o
characters
returns a pointer t o an i n t e g e r q u a n t i t y */
            
i n t ( * p [ l O ] ) ( v o i d ) ; /* p i s a 10-element array of pointers t o functions;
each function returns an i n t e g e r q u a n t i t y */
            
i n t (*p[lO])(char a); /* p i s a 10-element array of pointers t o functions;
each function accepts an argument which i s a character, and
returns an i n t e g e r q u a n t i t y */
            
i n t * ( * p [ l O ] ) ( c h a r a); /* p i s a 10-element array of pointers t o functions;
each function accepts an argument which i s a character, and
returns a pointer t o an i n t e g e r q u a n t i t y */
            
i n t * ( * p [ l O ] ) ( c h a r *a); /* p is a 10-element array of pointers t o functions;
each function accepts an argument which i s a pointer t o a
character, and
returns a pointer t o an i n t e g e r q u a n t i t y */            


