#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room36",
        "east"      :BO+"room29",
        "south"     :BO+"room30"
             ]));

}
