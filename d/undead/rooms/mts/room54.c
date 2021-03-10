#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room53",
        "west"      :MTS+"room55"
             ]));

}
