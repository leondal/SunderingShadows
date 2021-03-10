#include "../../undead.h"

inherit INH+"bound_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"path5",
        "west"      :BO+"path3"
             ]));

}
