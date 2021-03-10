#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room58",
        "west"      :MTS+"room60"
             ]));

}
