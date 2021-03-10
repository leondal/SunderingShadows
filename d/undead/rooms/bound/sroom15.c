#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path12",
        "west"      :BO+"path11",
        "east"      :BO+"sroom16",
        "south"     :BO+"sroom12"
             ]));

}
