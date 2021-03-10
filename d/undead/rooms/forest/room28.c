#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "swamp"     :BO+"sroom4",
        "west"      :PATH+"room27",
        "south"     :PATH+"room39"
             ]));

}
