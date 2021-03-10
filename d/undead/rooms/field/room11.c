#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BF+"room12",
        "south"     :BF+"room13"
             ]));

}

