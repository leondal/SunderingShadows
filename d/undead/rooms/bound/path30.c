#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path31",
        "south"     :BO+"path29"
             ]));

}
