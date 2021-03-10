#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :BO+"path16",
        "bridge"    :BO+"bridge",
        "south"     :BO+"sroom21",
        "southwest" :BO+"path14"
             ]));

}
