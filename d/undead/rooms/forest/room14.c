#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room7",
        "south"     :PATH+"room23",
        "northwest" :PATH+"room6"
             ]));

}
