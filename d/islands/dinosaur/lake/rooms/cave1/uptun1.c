#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Tunnel");
    set_long(
      "You are in what seems to be a long tunnel that travels more or less straight up and down.  Above you you can see the light from where the tunnel breaks the surface by the island in the middle of the lake.  Down is just darkness."
    );
    set_light(1);
    set_property("indoors", 1);
    set_listen("default", "You can hear rumbles from around the lake where somthing large is walking");
    set_items( ([
       "rock" : "You are sorrounded by the rock of the tunnel",
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "up" : "/d/islands/dinosaur/lake/rooms/deep9d.c",
      "down" : CAVEONE "uptun2.c",
    ]) );
}
