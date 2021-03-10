#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room",
        "east"      :PATH+"room7",
        "southeast" :PATH+"room14",
        "south"     :PATH+"room13"
             ]));

}
