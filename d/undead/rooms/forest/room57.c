#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :PATH+"room47",
        "east"      :PATH+"room58",
        "south"     :PATH+"room66",
        "west"      :PATH+"room56"
             ]));

}
