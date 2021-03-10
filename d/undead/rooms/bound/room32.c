#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room40",
        "south"     :BO+"room33"
             ]));

}
