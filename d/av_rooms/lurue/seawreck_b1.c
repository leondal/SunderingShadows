// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_b1");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^YELLOW%^The husk of a shipwreck%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Wedged between the large coral covered structure and the earth, a piece of wrecked ship lays here.  The wood is %^BLACK%^%^BOLD%^warped %^RESET%^%^ORANGE%^and %^CYAN%^twisted%^ORANG"
	"E%^, splintered and torn in some places.  A piece of mast lays over the top wrapped in some of the %^GREEN%^emerald green canvas %^ORANGE%^that once sailed this ship.  The canopy creating an unnatural"
	" %^BOLD%^%^BLACK%^cave %^RESET%^%^ORANGE%^deep within the cold ocean.  Though most of the ship appears shorn away, a wooden door provides access to somewhere deeper in the ship.  Whether the area beyo"
	"nd survived whole or not, is uncertain.%^RESET%^"
	);

    set_smell("default","
The water is thick with the taste of grime.");
    set_listen("default","Bubbles escape from your nose and mouth, tickling your ears.");

    
set_items(([ 
	({ "canvas", "cloth", "sails", "canopy" }) : "%^GREEN%^The thick cloth must be well made to have withstood what has happened to the ship already. Though you can see tears and rips here and there. The remains of the mast keep it pinned down, creating the small cave like area where you stand.%^RESET%^",
	({ "wood", "walls", "cracks", "holes" }) : "%^ORANGE%^The wooden walls of the ship are cracked and twisted.  Bent where they cracked against the structure above, they're not yet brittle enough to be broken apart fully and this part of the deck remains mostly in shape.%^RESET%^",
	({ "structure", "coral" }) : "%^ORANGE%^You can't see it from here, but you know the large, tower like structure is near, covered with life, covered coral, while it holds the remains of this ship trapped at its feet.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/seawreck_c10",
		"east" : "/d/av_rooms/lurue/seawreck_b2",
	]));

    set_door("ship door","/d/av_rooms/lurue/seawreck_b2","east","brass key","brass lock");
    add_lock("ship door","brass key","brass lock","This lock is made from brass that must have been enchanted to withstand damage, for unlike everything else about this sunken ship, the lock seems in perfect repair.");
    set_locked("ship door",1,"brass lock");
    lock_difficulty("ship door",-1000,"brass lock");
    set_open("ship door",0);
    set_string("ship door","knock","pounds on the ");
    set_string("ship door","open","With a hardy tug, you unstick the swollen wood door from its frame.");
    set_string("ship door","close","You shove the door closed, wedging it back into the frame.");
    set_door_description("ship door","This wooden door was once a beautiful piece of work. Carved and set with brass insets, the wood has since swollen and buckled, sticking it fast into the door frame.  If this wasn't bad enough, it appears that the locking mechanism is still intact.");
}