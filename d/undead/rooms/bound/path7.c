#include "../../undead.h"

inherit INH+"bound_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"path8",
        "west"      :BO+"path6"
             ]));

}
