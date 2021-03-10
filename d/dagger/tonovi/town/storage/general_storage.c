//changed to use the common general store list - it was essentially the same.
//anything special wanted here can still be added into the reset() function
//Styx 7/29/01

#include <std.h>
#include "/d/common/common.h"

inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Tonovi's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/dagger/tonovi/town/general_store"]) );
}

void reset() {
  ::reset();
}
