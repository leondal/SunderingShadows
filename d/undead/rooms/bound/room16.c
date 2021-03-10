#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room17",
        "west"      :BO+"room15"
             ]));

}
