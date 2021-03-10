#include "/d/shadow/mon/melnmarn.h"
#include "../tormdefs.h"
#include <std.h>
inherit "/d/common/inherit/wpn_storage";

void create() {
  ::create();
    set_properties((["light":2, "indoors":1]));
    set("short", "One of the Torm weapon storages");
    set("long", "Only supplies and such here.\n");
    set_property("no teleport",1);
    set_exits( (["up" : ROOMDIR+"weapon"]) );
}

void reset() {

::reset();
if(!present("scimitar"))
  new(OBJ+"scimitar")->move(this_object());
}

