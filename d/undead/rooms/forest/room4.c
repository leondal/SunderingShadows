#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :PATH+"room9",
        "southeast" :PATH+"room10",
        "southwest" :PATH+"room8"
             ]));

}
