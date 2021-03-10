#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room68",
        "east"      :PATH+"room76",
        "south"     :PATH+"room80",
        "west"      :PATH+"room74"
             ]));

}
