#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room3",
        "east"      :BF+"room15",
        "south"     :BF+"room6"
             ]));

}
