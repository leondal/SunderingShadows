#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room7",
        "west"      :MTS+"room5"
             ]));

}
