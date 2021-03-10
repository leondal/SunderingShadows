#include <std.h>
#include "../argabbr.h"
inherit INH+"argpath";

void create() {
    ::create();
    set_exits( (["east":PATH+"argpath37",
        "west":PATH+"argpath35"]) );

    if(mobs) { make_creatures(); }
}

void reset()
{
    if(mobs) { make_creatures(); }
    ::reset();
}
