#include "../../undead.h"

inherit INH+"mts_four.c"; // looks like the begging of another sub area that was never finished

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room12"
             ]));

}
