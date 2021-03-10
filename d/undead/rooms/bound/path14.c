#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"sroom21",
        "south"     :BO+"path13",
        "northeast" :BO+"path15"
             ]));

}
