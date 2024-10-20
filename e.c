#include <stdio.h>

int main()
{
    // int const *p = 5;
    
    int p = 5;
    int *ptr = p;
    printf("%d", ++(*ptr));
}