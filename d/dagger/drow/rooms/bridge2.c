#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_travel(DIRT_ROAD);
   set_terrain(CITY);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("North half of the bridge");
    set_long(
	"%^BLACK%^%^BLUE%^You stand upon the %^CYAN%^bridge "
 	"%^BLUE%^leading into drow city. The water beneath the "
	"bridge is dark and dreary looking. "
	"Ahead of you the drow city is cast over with a shadow of darkness "
	"and you feel an immense chill of evil touch your soul as you gaze "
	"upon it.%^RESET%^"
    );
    set_listen("default",
 	"The water gurgles beneath the bridge."
    );
    set_smell("default",
	"A pungent odor drifts up from the water beneath you."
    );
    set_items(([
	"water":"%^BOLD%^%^BLUE%^The water lays dark and gloomy beneath "
	"the bridge.%^RESET%^",
	"lake":"%^BLUE%^You estimate swimming in the lake would be dangerous "
	"to you.%^RESET%^",
	"bridge":"The bridge is old and rickety but supports your weight.",
	"city":"%^RED%^Ahead of you the city awaits your arrival and demise.",
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/bridge1",
	"north":"/d/dagger/drow/rooms/city1"
    ]));
}
