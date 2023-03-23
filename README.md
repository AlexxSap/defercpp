# defercpp

go-style defer function in c++

Example
```cpp
#include <iostream>
#include "defercpp.h"

int main()
{
    auto print1 = []() { std::cout << 1 << std::endl; };
    auto print3 = []() { std::cout << 3 << std::endl; };

    defer(print1);
    defer([&]() { std::cout << 2 << std::endl; });
    print3();
    
    return 0;
}
```cpp

output:
```
3
2
1
```
