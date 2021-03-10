#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room51",
        "east"      :BO+"room53",
        "west"      :BO+"room19"
             ]));

}
