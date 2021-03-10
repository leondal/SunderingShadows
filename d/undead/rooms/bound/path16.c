#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :BO+"path17",
        "southwest" :BO+"path15"
             ]));

}
