#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room21",
        "east"      :BF+"room30",
        "south"     :BF+"room37",
        "west"      :BF+"room19"
             ]));

}
