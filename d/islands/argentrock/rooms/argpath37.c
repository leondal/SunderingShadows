#include <std.h>
#include "../argabbr.h"
inherit INH+"argpath";

void create() {
    ::create();
    set_exits( (["east":PATH+"argpath38",
        "west":PATH+"argpath36",
        "north":PATH+"argpath28"]) );

    if(mobs) { make_creatures(); }
}

void reset()
{
    if(mobs) { make_creatures(); }
    ::reset();
}
