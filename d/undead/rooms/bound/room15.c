#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room16",
        "west"      :BO+"room14"
             ]));

}
