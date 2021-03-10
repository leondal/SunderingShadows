#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room3",
        "southeast" :MTS+"room5"
             ]));

}
