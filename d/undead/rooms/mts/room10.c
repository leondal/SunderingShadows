#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "southeast" :MTS+"room11",
        "west"      :MTS+"room9"
             ]));

}
