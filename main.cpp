#include <stdio.h>
#include "StringFunctions.hpp"

int main(void)
{
    char s1[10];
    char s2[] = "hello";

    StringCopy(s1, s2, 10, 0);

    puts(s1);

    return 0;
}
