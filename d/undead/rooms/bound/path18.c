#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :BO+"path19",
        "southwest" :BO+"path17"
             ]));

}
