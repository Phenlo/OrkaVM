#include <OrkaVM/orka.h>

#include <stdio.h>

int main( int argc, char * argv[] )
{
    static struct orka_env env;
    orka_env_init( &env, argc, argv );

    return 0;
}
