#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BF+"room31",
        "south"     :BF+"room15",
        "west"      :BF+"room3"
             ]));

}
