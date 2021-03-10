#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Tunnel");
    set_long(
      "You are far beneath the surface in a tunnel that seems to lead far underwater under the lake.  The tunnel walls around you are pitch black, you can barely see your hand in front of your face."
    );
    set_light(-1);
    set_property("indoors", 1);
    set_listen("default", "You can hear rumbles from around the lake where somthing large is walking");
    set_items( ([
       "rock" : "You are sorrounded by the rock of the tunnel",
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "west" : CAVEONE "uptun3.c",
      "up" : CAVEONE "uptun5.c",
      "down" : CAVEONE "uptun6.c",
    ]) );
}
