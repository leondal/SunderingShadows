#include <std.h>
#include "../argabbr.h"
inherit INH+"argpath";

void create() {
    ::create();
    set_exits( (["east":PATH+"argpath39",
        "west":PATH+"argpath37"]) );

    if(mobs) { make_creatures(); }
}

void reset()
{
    if(mobs) { make_creatures(); }
    ::reset();
}
