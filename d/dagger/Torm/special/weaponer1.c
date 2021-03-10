#include "/d/shadow/mon/melnmarn.h"
#include <std.h>
#include "../tormdefs.h"
inherit "/d/common/inherit/wpn_storage";

void create() {
  ::create();
    set_properties((["light":2, "indoors":1]));
    set("short", "Another weapon storage for Torm");
    set("long", "Only supplies and such here.\n");
    set_property("no teleport",1);
    set_exits( (["up" : ROOMDIR+"weapon"]) );
}

void reset() {

::reset();
 if(!present("trident of the seas") && !random(2))
  new(OBJ+"seatrident")->move(TO);
}

