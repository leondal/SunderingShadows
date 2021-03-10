#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room17",
        "east"      :BF+"room21",
        "south"     :BF+"room19",
        "west"      :BF+"room9"
             ]));

}
