#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room57",
        "east"      :BO+"room55",
        "west"      :BO+"room53"
             ]));

}
