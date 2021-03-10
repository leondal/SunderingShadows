#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BF+"room32",
        "south"     :BF+"room27",
        "west"      :BF+"room23"
             ]));

}
