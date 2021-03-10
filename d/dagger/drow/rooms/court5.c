#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Within the temple walls");
    set_long(
	"%^BLACK%^%^BLUE%^You stand within the %^CYAN%^temple "
 	"courtyard%^BLUE%^. The %^CYAN%^temple%^BLUE%^ is quite simple "
	"in detail and is formed of solid black "
	"obsidian stone. The roof of the %^CYAN%^temple%^BLUE%^ comes to a pinnacle "
   "directly at the center of its roof. There are no doors or windows visible "
	"and no apparent means to enter it from whence you stand. Numerous skeletons "
	"litter the ground before you.%^RESET%^" 
    );
    set_listen("default",
 	"You hear a faint chanting that seems to come through the walls of the temple."
    );
    set_smell("default",
	"There is a faint trace of an acidic odour in the room."
    );
    set_items(([
	"temple":"%^BOLD%^%^BLUE%^The temple is formed of black obsidian and there is no entrance from this point in the courtyard.%^RESET%^",
   "pinnacle":"%^MAGENTA%^The roof of the temple is pyramidical in shape and comes to a point at its apex.%^RESET%^",
	"skeletons":"The skeletons litter the ground. Most of the bones and skulls come from elves.",
	"stone":"%^RED%^The stone is warm to the touch.",
	"walls":"The temple walls stand twenty feet high.",
	"wall":"There is no apparent entrance into the temple.",
	"hint":"%^BLUE%^Find the elven elder to seek entrance.%^RESET%^"
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/court7",
	"north":"/d/dagger/drow/rooms/court3"
    ]));
}
