#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "meadow"    :BO+"room47",
        "east"      :PATH+"room6",
        "south"     :PATH+"room12"
             ]));

}

