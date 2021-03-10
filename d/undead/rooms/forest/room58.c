#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room47",
        "east"      :PATH+"room59",
        "south"     :PATH+"room67",
        "west"      :PATH+"room57"
             ]));

}
