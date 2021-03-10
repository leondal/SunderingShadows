#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room44",
        "east"      :PATH+"room56",
        "southeast" :PATH+"room65",
        "south"     :PATH+"room64",
        "southwest" :PATH+"room63",
        "west"      :PATH+"room54"
             ]));

}
