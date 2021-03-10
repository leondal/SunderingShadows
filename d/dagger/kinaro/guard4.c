#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
	set_short("1st Floor");
    set_long("Each of these %^BOLD%^%^RED%^guard towers %^RESET%^are 25"
			 " feet %^BOLD%^%^BLACK%^tall%^RESET%^, with %^ORANGE%^two"
			 " stories %^WHITE%^and a %^BOLD%^%^BLACK%^cellar%^RESET%^."
			 " They each have a squad of 6 %^BOLD%^%^RED%^dwarven guards"
			 " %^RESET%^on %^BOLD%^duty %^RESET%^at all times, whose duty"
			 " it is to patrol the walls. You are standing on the %^ORANGE"
			 "%^first floor%^WHITE%^, which features a %^BOLD%^kitchen%^RE"
			 "SET%^, %^ORANGE%^mess hall %^WHITE%^and %^CYAN%^lounge%^WHITE%^." 
   );
    set_smell("default", "You can smell food cooking from the mess hall.");
    set_listen("default", "You can overhear several conversations between the guards and the sound"
						  "of dwarves moving around in metal armor.");
    set_exits(([
	"south" : "/d/dagger/kinaro/guard3",
	"up" : "/d/dagger/kinaro/tower1"
      ]));
}

