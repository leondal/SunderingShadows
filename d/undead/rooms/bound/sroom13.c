#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path11",
        "east"      :BO+"sroom12",
        "south"     :BO+"sroom9",
        "west"      :BO+"sroom14"
             ]));

}
