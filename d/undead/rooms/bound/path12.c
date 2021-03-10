#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path13",
        "east"      :BO+"sroom18",
        "south"     :BO+"sroom15",
        "southwest" :BO+"path11"
             ]));

}
