#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room14",
        "east"      :BF+"room28",
        "south"     :BF+"room21",
        "west"      :BF+"room17"
             ]));

}
