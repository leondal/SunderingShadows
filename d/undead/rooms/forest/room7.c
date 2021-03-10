#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :PATH+"room",
        "south"     :PATH+"room14",
        "east"      :PATH+"room8",
        "west"      :PATH+"room6"
             ]));

}
