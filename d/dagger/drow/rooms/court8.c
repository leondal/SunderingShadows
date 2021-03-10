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
	"%^BLACK%^%^BLUE%^You stand within the entrance of the %^CYAN%^temple "
 	"courtyard%^BLUE%^ and now the %^CYAN%^temple%^BLUE%^ is clearly within "
	"view. It is quite simple in detail and is formed of solid black "
	"obsidian stone. The roof of the %^CYAN%^temple%^BLUE%^ comes to a pinnacle "
   "directly at the center of its roof. Ahead of you to the north stands the "
	"temple doors. This appears to be the only means of entrance to the temple.%^RESET%^" 
    );
    set_listen("default",
 	"You hear a faint chanting that seems to come through the doors of the temple."
    );
    set_smell("default",
	"There is a faint trace of an acidic odour in the room."
    );
    set_items(([
	"temple":"%^BOLD%^%^BLUE%^The temple is formed of black obsidian and there is no entrance from this point in the courtyard.%^RESET%^",
      "pinnacle":"%^MAGENTA%^The roof of the temple is pyramidical in shape and comes to a point at its apex.%^RESET%^",
	"doors":"The large double doors are sealed shut. It appears that they are covered in symbols.",
	"symbols":"The symbols on the doors are too far away to be seen clearly.",
	"stone":"%^RED%^The stone is warm to the touch.",
	"walls":"The temple walls stand twenty feet high.",
	"wall":"There is no apparent entrance into the temple.",
	"hint":"%^BLUE%^Find the elven elder to seek entrance.%^RESET%^"
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/temple",
	"west":"/d/dagger/drow/rooms/court6",
    "gate":"/d/dagger/drow/rooms/city18",
	"east":"/d/dagger/drow/rooms/court7"
    ]));
}
