#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :PATH+"room6",
        "east"      :PATH+"room2",
        "southeast" :PATH+"room7"
             ]));

}
