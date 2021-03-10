#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom24",
        "east"      :BO+"sroom29",
        "south"     :BO+"sroom31",
        "west"      :BO+"sroom27"
             ]));

}
