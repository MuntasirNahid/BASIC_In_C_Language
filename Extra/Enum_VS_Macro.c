//We can also use macros to define names constants. For example we can define ‘Working’ and ‘Failed’ using following macro.

#define Working 0
#define Failed 1
#define Freezed 2
// There are multiple advantages of using enum over macro when many related named constants have integral values.
// a) Enums follow scope rules.
// b) Enum variables are automatically assigned values. 
//Following is simpler

enum state  {Working, Failed, Freezed};