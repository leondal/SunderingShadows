#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room81",
        "west"      :MTS+"room79"
             ]));

}
