#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long(
     "%^BLUE%^After leaving the sliding chute room, the tunnel "
	"begins to stretch deep into the mountain. Various "
	"%^MAGENTA%^lichen%^BLUE%^ grow on the walls of the tunnel "
	"providing a feasible light source to see by. A feeling of fear "
	"hits you as you enter but quickly subsides as you begin to adjust "
	"to your surroundings. You passed through a good forty feet of "
	"tunnel to this point, most of the tunnel similar to where you are "
	"now, but stopped as something grabbed your "
	"attention.%^RESET%^"
    "\n%^BOLD%^%^RED%^You hear the hollow laughter of Grazzt."
    "%^RESET%^"
    );
    set_listen("default","You were sure you heard a cry for help come from "
	"deeper in the tunnel, but now all is silent."
    );
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and seems "
	"to provide the light source within the cavern tunnel.%^RESET%^",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
"west" : "/d/dagger/cave1/rooms/entrance",
	"north":"/d/dagger/drow/rooms/tun2"
    ]));
}
