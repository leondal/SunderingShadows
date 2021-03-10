#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room8",
        "east"      :BO+"room10",
        "south"     :BO+"room25",
        "west"      :BO+"room27"
             ]));

}
