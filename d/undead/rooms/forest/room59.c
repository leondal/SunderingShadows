#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :PATH+"room49",
        "east"      :PATH+"room60",
        "southeast" :PATH+"room69",
        "west"      :PATH+"room58",
        "northwest" :PATH+"room47"
             ]));

}
