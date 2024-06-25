#include "engine/mutation_engine.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Hello Mutation Engine!\n");

    if (mutation_engine_init() != 0)
    {
        return 1;
    }

    mutation_engine_run_loop();
    mutation_engine_close();
}

