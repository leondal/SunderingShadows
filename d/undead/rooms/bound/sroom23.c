#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom",
        "south"     :BO+"sroom26",
        "west"      :BO+"sroom22"
             ]));

}
