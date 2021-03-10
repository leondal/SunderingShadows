#include "/d/shadow/mon/melnmarn.h"
#include "../tormdefs.h"
#include <std.h>
inherit ROOM;

void create() {
  ::create();
    set_properties((["light":2, "indoors":1]));
  set_short("store room");
    set("long", "Only supplies and such here.\n");
    set_property("no teleport",1);
    set_exits( (["up" : ROOMDIR+"weapon"]) );
}

void reset() {

::reset();
  if(!present("furcloak")) new(OBJ+"furcloak.c")->move(TO);
  if(!present("furhat")) new(OBJ+"furhat.c")->move(TO);
  if(!present("furboots")) new(OBJ+"furboots.c")->move(TO);
  if(!present("furgloves")) new(OBJ+"furgloves.c")->move(TO);
}

