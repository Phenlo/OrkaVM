#ifndef __ORKAVM_ORKA_H__
#define __ORKAVM_ORKA_H__

#include <stdio.h>
#include <stdbool.h>

struct orka_env
{
    FILE * input;
    bool ia_mode;
};

extern void orka_env_init( struct orka_env * env, int argc, char * argv[] );

#endif
