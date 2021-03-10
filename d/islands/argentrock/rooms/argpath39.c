#include <std.h>
#include "../argabbr.h"

inherit INH+"argpath";

void create() {
    ::create();
    set_exits( (["west":PATH+"argpath38"]) );

    if(mobs) { make_creatures(); }
}

void reset()
{
    if(mobs) { make_creatures(); }
    ::reset();
}
