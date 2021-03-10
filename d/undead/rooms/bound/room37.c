#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room34",
        "east"      :BO+"room3",
        "south"     :BF+"room38",
        "west"      :BF+"room32"
             ]));

}
