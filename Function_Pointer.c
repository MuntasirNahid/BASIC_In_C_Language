
// This address is the entry point of the function and it is the address used when the function is called.

int Function(int,int);
int main()
{
	int (*Func)(int,int)=Function;
}


#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
    printf("Value of a is %d\n", a);
}
  
int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int) = &fun;
  
    /* The above line is equivalent of following two:

       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
  
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);
  
    return 0;
}
Output:

Value of a is 10


// Following are some interesting facts about function pointers.

 
// 1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.

// 2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

// 3) A function’s name can also be used to get functions’ address. For example, in the below program, we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works.


#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
    printf("Value of a is %d\n", a);
}
  
int main()
{ 
    void (*fun_ptr)(int) = fun;  // & removed
  
    fun_ptr(10);  // * removed
  
    return 0;
}
Output:

Value of a is 10
 
// 4) Like normal pointers, we can have an array of function pointers. Below example in point 5 shows syntax for array of pointers.

 
// 5) Function pointer can be used in place of switch case. For example, in below program, user is asked for a choice between 0 and 2 to do different tasks.


#include <stdio.h>
void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}
  
int main()
{
    // fun_ptr_arr is an array of function pointers
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    unsigned int ch, a = 15, b = 10;
  
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n");
    scanf("%d", &ch);
  
    if (ch > 2) return 0;
  
    (*fun_ptr_arr[ch])(a, b);
  
    return 0;
}

Enter Choice: 0 for add, 1 for subtract and 2 for multiply
2
Multiplication is 150 


// 6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.
// For example, consider the following C program where wrapper() receives a void fun() as parameter and calls the passed function.


// A simple C program to show function pointers as parameter
#include <stdio.h>
  
// Two simple functions
void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }
  
// A function that receives a simple function
// as parameter and calls the function
void wrapper(void (*fun)())
{
    fun();
}
  
int main()
{
    wrapper(fun1);
    wrapper(fun2);
    return 0;
}
Fun1
Fun2