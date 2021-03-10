#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :PATH+"room32",
        "south"     :PATH+"room43",
        "southeast" :PATH+"room44"
             ]));

}
