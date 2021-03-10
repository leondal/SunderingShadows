//set to inherit a common storage to add sheaths, climbing tools, etc.
//and make it easier to keep it up to date.

#include <std.h>

inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
 	set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/deku/town/gs_store"]) );
}

void reset() {
::reset();
    if(!present("waterskin") && !random(2)) {
        new("/d/antioch/antioch2/obj/waterskin")->move(TO);
    }
}
