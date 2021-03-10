#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit TUNNELS;

void create(){
    ::create();
    set_short("Underwater Tunnel");
    set_long(
      "You have entered what could only be an underwater tunnel.  In the light you can make out the walls of the tunnel all around you.  The water continues to press in all around you.  There is a soft glow emenating from the walls."
    );
    set_light(0);
    set_property("indoors", 1);
    set_items( ([
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
      "walls" : "The walls all around you are smooth, as if they have been worn smooth from years of water running along their length.",
    "glow" : "All along the walls a fuzzy green plant glows with a very soft light.",
    ]) );
    set_exits( ([
      "west" : TUNONE "tun37.c",
      "south" : TUNONE "tun35.c",
    ]) );
    add_stuff();
}
