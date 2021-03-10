// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_b2");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^YELLOW%^The husk of a shipwreck%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Clearly the captain's quarters of a large sailing vessel, this wooden chamber is wedged between the towering coral covered structure and the earth.  Thus pinned, it waits for %^BLUE"
	"%^water%^ORANGE%^, %^WHITE%^pressure %^ORANGE%^and %^YELLOW%^time %^RESET%^%^ORANGE%^to finish what some storm began.  The wood is swollen and thick with water.  Cracks and holes reveal themselves her"
	"e and there, though only the one %^RED%^passage %^ORANGE%^seems big enough to fit through.  That, and the door which likely led to the rest of the ship at one time.  The broken remains of furniture li"
	"tter the floor of the water filled chamber, including a large %^BOLD%^%^WHITE%^silver cage %^RESET%^%^ORANGE%^with %^YELLOW%^amber runes%^RESET%^%^ORANGE%^.%^RESET%^"
	);

    set_smell("default","
The water is thick with the taste of grime.");
    set_listen("default","You can hear something moving around beyond the door.");

    
set_items(([ 
	"cage" : "%^BOLD%^%^WHITE%^Made from bars of silvery metal lined with a %^RESET%^%^ORANGE%^coppery mesh%^BOLD%^%^WHITE%^, this cage is large enough to contain a horse or other big animal, as well as smaller creatures that might be placed within it.  The %^RESET%^%^ORANGE%^coppery mesh %^BOLD%^%^WHITE%^is thin but resilient bending and flexing while snapping back into place when released.  It is affixed to the silvery bars with %^YELLOW%^amber clamps %^WHITE%^each of which burn with an %^RESET%^%^MAGENTA%^inner power%^BOLD%^%^WHITE%^.  %^RESET%^",
	({ "structure", "coral" }) : "%^ORANGE%^You can't see it from here, but you know the large, tower like structure is near, covered with life, covered coral, while it holds the remains of this ship trapped at its feet.%^RESET%^",
	({ "wood", "walls", "cracks", "holes" }) : "%^ORANGE%^The wooden walls of the ship are cracked but not yet brittle enough to be broken apart.  In time though, water and pressure will crush even these strong walls. The small cracks and holes provides a %^CYAN%^view%^ORANGE%^ or two beyond the cabin's walls, but the rest still stands.%^RESET%^",
	"view" : "%^CYAN%^You press your eye up against the wall, near the door and peer through one of the larger cracks.  Beyond you can see a part of the ship's deck, shrouded in the remains of a green cloth that must be the canvas sails.  The remains of the mast keep it pinned down, but where the mast leans against the cabin, there is a small dark space.  One which seems to have something moving within it.%^RESET%^",
	"furniture" : "%^ORANGE%^There isn't much to be found.  Once some windows surrounded one end of this cabin, looking out on the sea, but they've been smashed with the impact, allowing water to rush in and further damage the once plush chairs and tables.  The only thing not damaged is the %^WHITE%^%^BOLD%^silvery cage%^RESET%^%^ORANGE%^ but its far too large to extract through that small hole you came in through.  If only you could get that door open.  Maybe if you could find a way to the other side.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/seawreck_b1",
		"out" : "/d/av_rooms/lurue/seawreck_d9",
	]));

    set_door("ship door","/d/av_rooms/lurue/seawreck_b1","west","brass key","brass lock");
    add_lock("ship door","brass key","brass lock","This lock is made from brass that must have been enchanted to withstand damage, for unlike everything else about this sunken ship, the lock seems in perfect repair.");
    set_locked("ship door",1,"brass lock");
    lock_difficulty("ship door",-1000,"brass lock");
    set_open("ship door",0);
    set_string("ship door","knock","pounds on the ");
    set_string("ship door","open","With a hardy tug, you unstick the swollen wood door from its frame.");
    set_string("ship door","close","You shove the door closed, wedging it back into the frame.");
    set_door_description("ship door","This wooden door was once a beautiful piece of work. Carved and set with brass insets, the wood has since swollen and buckled, sticking it fast into the door frame.  If this wasn't bad enough, it appears that the locking mechanism is still intact.");
}