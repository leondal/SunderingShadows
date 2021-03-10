#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room51",
        "west"      :PATH+"room61",
        "northwest" :PATH+"room50"
             ]));

}
