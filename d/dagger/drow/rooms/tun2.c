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
	"%^BLUE%^The tunnel continues deeper into the mountainside and "
   "with its depth comes a deeper fear that causes chills to run "
	"down your spine. Visions of the tunnel around you collapsing "
	"fills your mind. The same %^MAGENTA%^lichen%^BLUE%^ "
	"covers the walls here as before and still provides a sufficent "
	"light source to see by. You paused at this point in the tunnel, "
	"fifty more feet deeper than the last time you stopped, as ahead "
	"the tunnel seems to widen into an intersection.%^RESET%^"
    );
    set_listen("default",
	"You aren't sure but you think you heard voices coming from the "
	"intersection."
    );
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern "
	"tunnel.%^RESET%^",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/tun1",
	"north":"/d/dagger/drow/rooms/tun3"
    ]));
}
