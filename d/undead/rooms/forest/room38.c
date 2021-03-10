#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room27",
        "south"     :PATH+"room50",
        "west"      :PATH+"room37"
             ]));

}
