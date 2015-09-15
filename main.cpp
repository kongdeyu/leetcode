
#include <cstdlib>

#include <iostream>
#include <vector>

#define WARN_IF(EXP) \
    do \
    { \
        printf(#EXP); \
    } while(0)

int32_t main()
{
    int32_t xxx = 1;
    WARN_IF(xxx == 1);
    return 0;
}
