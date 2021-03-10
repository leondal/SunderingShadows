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
	"%^CYAN%^You have entered the fog and instantly become paralyzed "
	"with fear. Haunting voices ring in your ears and you follow the "
	"voices deeper into the fog. You are unable to resist it and "
	"have lost complete control of your body. After moving for what "
	"seemed like miles through the dense fog you regain control of "
	"your body...you stand at the edge of the fog and can walk "
	"forward with ease. But no matter how hard you try you cannot go "
	"back the way you came.%^RESET%^"
    );
    set_listen("default",
	"The howling roars in your ears and strange singing blends "
	"harmonically in with the howl."
    );
    set_smell("default",
   "It smells of sulfur causing you difficulty in breathing."
    );
    set_items(([
    	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern "
	"tunnel.%^RESET%^",
	"fog":"%^CYAN%^The fog swirls around you and traps your retreat "
	"to the south.%^RESET%^",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"north": RPATH "tun12"
    ]));
}
