#include <std.h>
#include "../juran.h"
//  inherit "/d/shadow/room/muuldaan/inherit/general";
inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Juran's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : JROOMS+"gs"]) );
}

void reset() {
  ::reset();
}
