#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :BO+"path32"
             ]));

}
