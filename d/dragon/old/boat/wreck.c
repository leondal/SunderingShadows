#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Dark Oliphant");
    set_long("%^BOLD%^%^BLUE%^
You have managed to stumble upon a large body of water.  A foggy musty mist
hangs in the air, which makes it difficult to see the shoreline.  Through
the muggy mist, upon the shore, you notice a large lifeless boat.");
    set_exits(([
       "south" : "/d/deku/open/forestxx"
      ]));
    set_listen("default","There is a very slight howl within the wind.");
    set_items(([
       "boat":"The boat looks very lifeless beached upon the dirty shoreline."
    ] ));
}
