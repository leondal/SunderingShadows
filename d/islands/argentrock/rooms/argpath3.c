#include <std.h>
#include "../argabbr.h"
inherit INH+"argpath";

void create() {
    ::create();
    set_exits( (["east":PATH+"argpath4",
        "south":PATH+"argpath12",
        "west":PATH+"argpath2"]) );

    if(mobs) { make_creatures(); }
}

void reset()
{
    if(mobs) { make_creatures(); }
    ::reset();
}
