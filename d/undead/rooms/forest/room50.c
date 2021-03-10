#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room38",
        "east"      :PATH+"room51",
        "southeast" :PATH+"room62",
        "west"      :PATH+"room49"
             ]));

}
