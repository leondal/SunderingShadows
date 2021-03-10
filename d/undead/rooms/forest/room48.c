#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :PATH+"room49",
        "west"      :PATH+"room47"
             ]));

}
