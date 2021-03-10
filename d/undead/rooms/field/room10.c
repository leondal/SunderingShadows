#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room9",
        "east"      :BF+"room19",
        "south"     :BF+"room12"
             ]));

}
