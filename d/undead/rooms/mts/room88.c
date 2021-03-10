#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "southeast" :MTS+"room87",
        "west"      :MTS+"room89"
             ]));

}
