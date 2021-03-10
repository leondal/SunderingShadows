#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :BO+"path32",
        "south"     :BO+"path30"
             ]));

}
