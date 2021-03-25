#ifndef __MY_HANDLE_H__
#define __MY_HANDLE_H__

#ifdef __cplusplus
extern "C"
{
#endif
// #include <typedef.h>
#include "./errcode.h"
    typedef unsigned int result_t;
    typedef void *my_handle_t;

    my_handle_t create_handle(const char *name);
    result_t operate_on_handle(my_handle_t handle);
    void close_handle(my_handle_t handle);

#ifdef __cplusplus
}
#endif

#endif