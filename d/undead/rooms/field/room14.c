#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room23",
        "south"     :BF+"room20",
        "west"      :BF+"room16"
             ]));

}
