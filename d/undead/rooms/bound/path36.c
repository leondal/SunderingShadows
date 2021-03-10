#include "../../undead.h"

inherit INH+"bound_three.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"path35",
        "west"      :BO+"path37"
             ]));

}
