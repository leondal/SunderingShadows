#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("Bridge Area");
    set_long(
@KAYLA
You are riding in a mine car across the bottomless chasm in the mines.
As you look down the sheer magnitude of the gorge baffles you
and you become momentarily dizzy.  You wonder where this track
is leading!
KAYLA
    );
    set_exits(([
    ] ));
    set_items(([
    ] ));
}
