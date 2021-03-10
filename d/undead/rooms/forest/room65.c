#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :PATH+"room55",
        "south"     :PATH+"room72"
             ]));

}
