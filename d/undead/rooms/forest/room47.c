#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room35",
        "east"      :PATH+"room48",
        "southeast" :PATH+"room59",
        "south"     :PATH+"room58",
        "southwest" :PATH+"room57"
             ]));

}
