/*
//getc(), getchar(), getch() and getche()

All of these functions read a character from input and return an integer value.
The integer is returned to accommodate a special value used to indicate failure.
The value EOF is generally used for this purpose.

##---------------------------------getc()----------------------##
It reads a single character from a given input stream and returns the corresponding
 integer value (typically ASCII value of read character) on success. It returns EOF on failure.

Syntax:

int getc(FILE *stream); 

Example:

#include <stdio.h>
int main()
{
   printf("%c", getc(stdin));
   return(0);
}
Input: g (press enter key)
Output: g 

or

#include <stdio.h>
int main()
{
   printf("%d", getc(stdin));
   return(0);
}
Input: a (press enter key)
Output: 97 

##---------------------------getchar()--------------------------------------##

The difference between getc() and getchar() is getc() can read from any input stream, but getchar() reads from standard input.

**So getchar() is equivalent to getc(stdin).

Syntax:

int getchar(void); 
Example:

#include <stdio.h>
int main()
{
   printf("%c", getchar());
   return 0;
}
Input: g(press enter key)
Output: g 





##---------------------------------getch()---------------------------------------##
getch() is a nonstandard function and is present in conio.h header file which is mostly
 used by MS-DOS compilers like Turbo C. It is not part of the C standard library or ISO C.

 Like above functions, it reads also a single character from keyboard.
 But it does not use any buffer, so the entered character is immediately returned without waiting for the enter key.
Syntax:

int getch();
Example:

#include <stdio.h>
#include <conio.h>
int main()
{
   printf("%c", getch());   
   return 0;
}
Input:  g (Without enter key)
Output: Program terminates immediately.
        But when you use DOS shell in Turbo C, 
        it shows a single g, i.e., 'g'



##------------------------getche()------------------------------##
Like getch(), this is also a non-standard function present in conio.h. It reads a single character from the keyboard and displays immediately on output screen without waiting for enter key.

Syntax:

int getche(void); 

Example:

#include <stdio.h>
#include <conio.h>
int main()
{
  printf("%c", getche());
  return 0;
}
Input: g(without enter key as it is not buffered)
Output: Program terminates immediately.
        But when you use DOS shell in Turbo C, 
        double g, i.e., 'gg'


*/