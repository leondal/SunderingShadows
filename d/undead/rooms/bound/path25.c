#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path26",
        "southwest" :BO+"path24"
             ]));

}
