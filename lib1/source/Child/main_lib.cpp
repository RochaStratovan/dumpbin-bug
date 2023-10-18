#include "Child/main_lib.h"
#include "GrandChild/main_lib.h"
#include <cstdio>


void child(void)
{
    printf("This is the child\n");
    grandChild();
}
