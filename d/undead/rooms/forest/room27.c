#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room18",
        "east"      :PATH+"room28",
        "south"     :PATH+"room38",
        "west"      :PATH+"room26"
             ]));

}
