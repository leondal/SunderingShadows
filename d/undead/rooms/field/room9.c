#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room7",
        "east"      :BF+"room18",
        "south"     :BF+"room10",
        "west"      :BF+"room8"
             ]));

}