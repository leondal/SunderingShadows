#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom12",
        "east"      :BO+"sroom7",
        "south"     :BO+"sroom6",
        "west"      :BO+"sroom9"
             ]));

}
