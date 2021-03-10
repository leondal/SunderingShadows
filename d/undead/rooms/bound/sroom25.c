#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom22",
        "east"      :BO+"sroom26",
        "south"     :BO+"sroom29",
        "west"      :BO+"sroom24"
             ]));

}
