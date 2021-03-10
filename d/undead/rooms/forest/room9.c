#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room4",
        "east"      :PATH+"room10",
        "south"     :PATH+"room16",
        "west"      :PATH+"room8"
             ]));

}
