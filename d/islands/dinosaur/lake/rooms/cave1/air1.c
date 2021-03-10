#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit WATER;

void create(){
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FRESH_BLAZE);
    set_air_pocket(400);
    set_short("A small air pocket");
    set_long(
      "Over time this room has filled with air bubbling up from below the cave's depths.  You can breathe here for a short time, but you can taste the air getting stale already."
    );
    set_light(2);
    set_items( ([
      "rock" : "You are sorrounded by the rock of the tunnel",
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
      "lichen" : "All around you a green lichen glows giving this room some light.",
    ]) );
    set_exits( ([
      "down" : CAVEONE "cave33-3.c",
    ]) );
}
