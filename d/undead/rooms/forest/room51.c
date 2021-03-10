#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room39",
        "northeast" :PATH+"room40",
        "east"      :PATH+"room52",
        "south"     :PATH+"room62",
        "west"      :PATH+"room50"
             ]));

}
