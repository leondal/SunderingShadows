#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room33",
        "east"      :BO+"room2",
        "south"     :BO+"room37",
        "west"      :BO+"room36"
             ]));

}
