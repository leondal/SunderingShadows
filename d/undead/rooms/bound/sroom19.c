#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom21",
        "west"      :BO+"path13",
        "east"      :BO+"sroom20",
        "south"     :BO+"sroom18"
             ]));

}
