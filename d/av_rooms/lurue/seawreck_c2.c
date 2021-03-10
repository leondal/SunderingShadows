// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c2");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^A sunken structure%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Once a plush and well appointed room, what remains is little more then piles of %^ORANGE%^rotted wood%^CYAN%^ covered by the %^GREEN%^algae %^CYAN%^that grows thickly within this dark"
	"ness.  Tiny %^RED%^crustaceans %^CYAN%^dart in and out of holes within the sprawling mass.  Making their homes amongst the %^BOLD%^%^BLACK%^metal slivers %^RESET%^%^CYAN%^that still remain after the w"
	"ooden beams have surrendered to the currents.  On one wall, the ragged tatters of a %^WHITE%^wall hanging %^CYAN%^drift, all but chewed up by the %^WHITE%^fish %^CYAN%^that dart about this room.  Anot"
	"her chamber lays beyond as does the collapsed hall behind you.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");

    
set_items(([ 
	({ "hanging", "wall" }) : "%^BOLD%^%^BLACK%^Hanging from the back wall are the algae eaten tatters of a wall hanging.  Looking close you can see what appears to be a tall tower on top of a island plateau.  In front of the tower a garden maze extends in a vast circle around the building.  Curiously, you think you can see horrific creatures roaming within the maze.%^RESET%^",
	({ "crustations", "fish" }) : "%^BOLD%^%^BLACK%^Living within the remains of this room are tiny fish and the crabs, lobster and other animals which feed upon such prey.  Most dart away into crevices as soon as you approach.%^RESET%^",
	({ "metal", "wood", "rubble", "remains" }) : "%^RESET%^%^ORANGE%^Judging by where the remains of wood and metal are located, this was once a bedroom. Though there is little left of the bed or other furniture, there is some shape to it that suggests it was a plush and comfortable apartment at one point.%^RESET%^",
	"algae" : "%^GREEN%^Algae grows over most the room, covering it in a thin layer of living green carpet.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/seawreck_c3",
		"east" : "/d/av_rooms/lurue/seawreck_c1",
	]));

}