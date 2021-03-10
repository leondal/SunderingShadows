#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room15",
        "east"      :BF+"room14",
        "south"     :BF+"room17",
        "west"      :BF+"room6"
             ]));

}
