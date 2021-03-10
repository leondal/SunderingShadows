#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room57",
        "west"      :MTS+"room59"
             ]));

}
