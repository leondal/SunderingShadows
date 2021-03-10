#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BF+"room22",
        "south"     :BF+"room4",
        "west"      :BF+"room2"
             ]));

}

