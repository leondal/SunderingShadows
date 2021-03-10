#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_property("no sinking", 1);
    set_short("Underwater Tunnel");
    set_long(
      "You can make out a little light here from some glowing blue substance on the wall.  You have dropped onto a plate sticking out from the nearby north wall, but as you look around the plate all around you it drops into pitch blackness."
    );
    set_light(1);
    set_property("indoors", 1);
    set_listen("default", "You can hear rumbles from around the lake where somthing large is walking");
    set_items( ([
       "rock" : "You are sorrounded by the rock of the tunnel",
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "up" : CAVEONE "uptun6.c",
      "east" : CAVEONE "caveL1R2",
      "south" : CAVEONE "cave13+1",
      "east" : CAVEONE "cave12+0",
      "west" : CAVEONE "cave14+0",
    ]) );
}
