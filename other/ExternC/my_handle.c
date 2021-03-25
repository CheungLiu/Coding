#include "./my_handle.h"
#include <stdio.h>
my_handle_t create_handle(const char *name)
{
    return (my_handle_t)0;
}

result_t operate_on_handle(my_handle_t handle)
{
    return 0;
}

void close_handle(my_handle_t handle) {}

int main()
{
    printf("%d\n", 10);
    printf("%f\n", 10);
    return 0;
}