#include <OrkaVM/config.h>
#include <OrkaVM/orka.h>

#include <string.h>
#include <stdlib.h>

struct orka_opt
{
    const char * name;
    const char * code;
    const char * help;
    void ( * parse )( struct orka_env *, int *, int, char ** );
};

static void parse_help( struct orka_env *, int *, int, char ** );
static void parse_version( struct orka_env *, int *, int, char ** );

static struct orka_opt option[] = {
    {
        "--help", "-h",
        "Show this help screen",
        &parse_help
    },
    {
        "--version", "-v",
        "Show the version of this program",
        &parse_version
    }
};

#define OPTIONS ( sizeof( option ) / sizeof( struct orka_opt ))

void orka_env_init( struct orka_env * env, int argc, char ** argv )
{
    for( int i = 0; i < argc; i++ )
    {
        for( int j = 0; j < OPTIONS; j++ )
        {
            if( ( option[ j ].code && !strcmp( argv[ i ], option[ j ].code )) ||
                !strcmp( argv[ i ], option[ j ].name ))
            {
                option[ j ].parse( env, &i, argc, argv );
                break;
            }
        }
    }
}

static void parse_help( struct orka_env * env, int * argi, int argc, char ** argv )
{
    printf( "Usage: %s [OPTIONS] [FILE]\n", argv[ 0 ] );
    printf( "Options:\n" );

    for( int i = 0; i < OPTIONS; i++ )
    {
        if( option[ i ].code != NULL )
        {
            printf( "    %s, %-12s    %s\n",
                    option[ i ].code,
                    option[ i ].name,
                    option[ i ].help
            );
        }
        else
        {
            printf( "        %-12s    %s\n",
                    option[ i ].name,
                    option[ i ].help
            );
        }
    }

    exit( EXIT_SUCCESS );
}

static void parse_version( struct orka_env * env, int * argi, int argc, char ** argv )
{
    printf( "OrkaVM " ORKAVM_VERSION " by " ORKAVM_AUTHOR "\n" );
    exit( EXIT_SUCCESS );
}
