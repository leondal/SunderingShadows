#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room28",
        "east"      :PATH+"room40",
        "south"     :PATH+"room51"
             ]));

}
