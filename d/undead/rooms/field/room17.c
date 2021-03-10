#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room16",
        "east"      :BF+"room20",
        "south"     :BF+"room18",
        "west"      :BF+"room7"
             ]));

}