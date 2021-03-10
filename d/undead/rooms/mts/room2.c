#include "../../undead.h"

inherit INH+"mts_three.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"entrance",
        "southwest" :MTS+"room"
             ]));

}