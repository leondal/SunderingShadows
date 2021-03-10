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
	"%^BLUE%^The tunnel has come to a bend here and you begin to feel "
	"a shaking from under your feet. Small pools of water from at your "
	"feet and you suspect that there is an underground river beneath "
	"you. This fact alone makes you worry about the tunnel collapsing. "
	"The %^MAGENTA%^lichen%^BLUE%^ still grows in the cavern at this "
	"point and manages to provide a light source for you to see "
	"by.%^RESET%^"
    );
    set_listen("default","The sound of rushing water comes from beneath "
	"your feet."
    );
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern "
	"tunnel.%^RESET%^",
	"pools":"%^BLUE%^The pools were most likely caused by the "
	"underground river that runs beneath your feet.%^RESET%^",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"northwest": RPATH "tun5",
	"northeast": RPATH "tun7"
    ]));
}
