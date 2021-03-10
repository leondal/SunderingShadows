#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom16",
        "east"      :BO+"sroom10",
        "south"     :BO+"sroom7",
        "west"      :BO+"sroom12"
             ]));

}
