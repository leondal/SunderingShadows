#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room32",
        "east"      :BF+"room38",
        "south"     :BF+"room34"
             ]));

}