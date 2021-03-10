#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room34",
        "east"      :BF+"room40",
        "south"     :BF+"room36"
             ]));

}