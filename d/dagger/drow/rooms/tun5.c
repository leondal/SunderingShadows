#include "/d/dagger/drow/short.h"
#include <std.h>
inherit "std/room";
void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long(
	"%^BLUE%^The tunnel continues to wind along here for about thirty "
	"feet from the intersection. The %^MAGENTA%^lichen%^BLUE%^ is more "
	"sparce here and is getting more difficult to see your way "
	"clearly. %^WHITE%^Cobwebs%^BLUE%^ hang from the ceiling and walls, "
	"however many of them have been broken as though something disturbed "
	"them while passing through.%^RESET%^"
    );
    set_listen("default","It is dead silent here.");
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and seems "
	"to provide the light source within the cavern tunnel.%^RESET%^",
	"cobwebs":"While they are normal sized cobwebs, there is a lot "
	"of them. Something has disturbed them recently.",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows on "
	"the walls here."
    ]));
    set_exits(([
	"west": RPATH "tun3",
	"southeast": RPATH "tun6"
    ]));
}
