#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :BO+"path25",
        "south"     :BO+"path23"
             ]));

}
