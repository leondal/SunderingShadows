#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room27",
        "south"     :BF+"room29",
        "west"      :BF+"room20"
             ]));

}
