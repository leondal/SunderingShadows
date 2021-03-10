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
There seems to be some sort of platform here, leading off to the north.
Maybe this is where the railing connects to the other sections of the
mine.
KAYLA
    );
    set_exits(([
    "north" : "chute"
    ] ));
    set_items(([
    "platform" : "A small landing dock for the minecar."
    ] ));
}
