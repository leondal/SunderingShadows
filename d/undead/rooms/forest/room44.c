#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :PATH+"room31",
        "northeast" :PATH+"room33",
        "east"      :PATH+"room45",
        "south"     :PATH+"room55"
             ]));

}
