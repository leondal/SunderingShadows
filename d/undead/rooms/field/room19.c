#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room18",
        "east"      :BF+"room24",
        "south"     :BF+"room25",
        "west"      :BF+"room10"
             ]));

}
