#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room",
        "south"     :BO+"room4",
        "west"      :BO+"room37",
        "north"     :BO+"room2"
             ]));

}
