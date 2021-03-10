#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room64",
        "east"      :PATH+"room72",
        "northwest" :PATH+"room63"
             ]));

}
