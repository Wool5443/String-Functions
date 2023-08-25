#include <stdio.h>
#include "string_functions.hpp"

int main()
{
    char s1[10];
    char s2[] = "HOLA";

    StringCopy(s1, s2, 10);

    puts(s1);

    printf("%d\n", StringCompare(s1, s2));

    return 0;
}