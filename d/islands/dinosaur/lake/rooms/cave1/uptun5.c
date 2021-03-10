#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Tunnel");
    set_air_pocket(150);
    set_long(
      "Your head has broken the surface of the water into what looks to be a small air pocket in these strange underwater tunnels.  All around the cave you can see strange lichen glowing, giving this empty room light.  The problem is that you can taste the air getting stale already."
    );
    set_light(2);
    set_property("indoors", 1);
    set_listen("default", "You can hear rumbles from around the lake where somthing large is walking");
    set_items( ([
       "rock" : "You are sorrounded by the rock of the tunnel",
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
      "lichen" : "All around you a green lichen glows giving this room some light.",
    ]) );
    set_exits( ([
      "down" : CAVEONE "uptun4.c",
    ]) );
}
