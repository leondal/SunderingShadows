#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room4",
        "east"      :BF+"room16",
        "south"     :BF+"room7",
        "west"      :BF+"room5"
             ]));

}
