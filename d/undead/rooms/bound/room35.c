#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room33",
        "south"     :BO+"room36"
             ]));

}
