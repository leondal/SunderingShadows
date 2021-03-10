// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c7");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^A sunken structure%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Long since submerged by the forces of nature, this ancient structure has been overrun by %^RESET%^%^CYAN%^se%^GREEN%^a %^CYAN%^l%^BLUE%^i%^CYAN%^fe%^BOLD%^%^BLACK%^.  Unlike the exter"
	"ior, the interior of this structure contains no coral, but is instead covered in various clusters of underwater %^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^CYAN%^g%^GREEN%^a%^CYAN%^e %^BOLD%^%^BLACK%^and %"
	"^RESET%^%^CYAN%^se%^BLUE%^a%^GREEN%^w%^CYAN%^e%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^.  The thick clumps grow heavily upon the stone walls, clinging to the mortar lines and crumbling awa"
	"y at the wooden supports.  More then one piece of the %^RESET%^floor %^BOLD%^%^BLACK%^has given away and left a passage going down.  Likewise, %^RESET%^%^ORANGE%^doors %^BOLD%^%^BLACK%^that once led t"
	"o other parts of this tower have rotted away giving access to the rooms beyond.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");

    
set_items(([ 
	({ "doors", "door" }) : "%^RESET%^%^ORANGE%^They appear to all but have rotted away.%^RESET%^",
	({ "wood", "walls", "stone" }) : "%^BOLD%^%^BLACK%^Long submerged, this building has begun to give way under the pressure of the water and the sea life which grows upon it.  The stones that make up the majority of the building still seem strong, but the wood has all but rotted away, giving easy access to most of the rooms and floors of this ancient tower.%^RESET%^",
	({ "algae", "seaweed", "sea weed" }) : "%^GREEN%^Thick clumps of algae and seaweed grow through out the interior of this building.  Their heavy presence providing ample food and hideaways for the myriad tiny %^WHITE%^fish %^GREEN%^and %^RED%^crustaceans %^GREEN%^that make their home here.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/seawreck_c9",
		"up" : "/d/av_rooms/lurue/seawreck_c4",
		"east" : "/d/av_rooms/lurue/seawreck_c8",
	]));

    set_door("main entrance","/d/av_rooms/lurue/seawreck_c9","west","void key","entry lock");
    add_lock("main entrance","void key","entry lock","Although covered in brass, the lock itself appears to be made of something else.  A dark swirling energy looks to be contained between the lock's face plates, making you wonder just what would be needed to unlock such a door.");
    set_locked("main entrance",1,"entry lock");
    lock_difficulty("main entrance",-1000,"entry lock");
    set_open("main entrance",0);
    set_string("main entrance","knock","pounds on the sodden wood of the ");
    set_string("main entrance","open","With a heave you pull the doors open, cracking the door frame and sending a thick cloud of dust and grime into the water.");
    set_string("main entrance","close","With all your effort, you push the door into its swollen frame.");
    set_door_description("main entrance","This heavy wooden door once made a grand entry.  Crafted from beautifully carved ironwood and set with ornate brass fixtures, the double doors are now thick and swollen by the water and wedged tightly into the door frame.  You're not sure you could ever pull them open, even if you could find a way to unlock them.");
}