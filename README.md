# String Functions
This library contains my versions of the string functions found in string.h.

## Installation

```bash
git clone https://github.com/Wool5443/String-Functions
make
```

## Usage

```c++
#include "string_functions.hpp"

const int S1_SIZE = 50;

char s1[S1_SIZE] = "Hello";
char s2[] = ", world!";

size_t s1Length = StringLength(s1); // 5
size_t s2Length = StringLength(s2); // 8

StringCat(s1, s2, S1_SIZE);
puts(s1); // Hello, world!

s1Length = StringLength(s1);
char s3[s1Length + 1] = "";

StringCopy(s3, s1, s1Length + 1);
puts(s3); // Hello, world!
```

