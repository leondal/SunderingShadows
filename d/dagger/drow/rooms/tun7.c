#include "/d/dagger/drow/short.h"
#include <std.h>
inherit "/std/room";
void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long(
	"%^BLUE%^You pause as you come to an opening in the tunnel. To "
	"the northeast the tunnel widens into a small chamber and from "
	"here you can see that the ceiling of the chamber has collapsed. "
	"However, despite the rubble, you imagine you could move into the "
	"room on top of the rubble to take a closer look.%^RESET%^"
    );
    set_listen("default","The whole scene cries danger to your senses.");
    set_items(([
    	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern "
	"tunnel.%^RESET%^",
	"rubble":"The ceiling of the chamber to the northeast has collapsed "
	"and much of the rubble has spilled into this area as well.",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"southwest": RPATH "tun6",
	"northeast": RPATH "tun8"
    ]));
}
