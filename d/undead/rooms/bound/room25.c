#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room26",
        "east"      :BO+"room23",
        "south"     :BO+"room24"
             ]));

}
