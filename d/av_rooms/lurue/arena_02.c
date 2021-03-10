// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_02");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RED%^The abandoned halls of the Seneca Arena%^RESET%^");

    set_long("%^RESET%^The ominous %^RED%^%^BOLD%^Warriors Gate %^RESET%^dominates the eastern end of this open area courtyard, rising high over the wide-open courtyard you find yourself in.  Here, %^BOLD%^%^RED%^c"
	"o%^YELLOW%^lo%^GREEN%^rf%^BLUE%^ul %^RESET%^booths were once set up, selling food, drink and trinkets to a blood-thirsty crowd of spectators come to watch the gladiators fight in mortal combat.  To ei"
	"ther side of this courtyard, large sweeping staircases lead upward to the two crescent-shaped seating areas.  Fallen into disrepair, the courtyard is overrun with %^GREEN%^weeds %^RESET%^and %^BOLD%^%"
	"^BLACK%^trash%^RESET%^.  "
	);

    set_smell("default","
Dust and rot tingle your nose.");
    set_listen("default","The coo and chirp of nesting birds reaches you once in a while.");

    set_search("trash","%^BOLD%^%^BLACK%^You search around in the trash and find a notice for an upcoming battle between %^YELLOW%^Champion Kel Karteni%^BLACK%^ and someone called %^RESET%^%^MAGENTA%^The Night Glove%^BOLD%^%^BLACK%^.  The battle was scheduled for 10 Colddays, 597 SG at noon.%^RESET%^");
    
set_items(([ 
	({ "weeds", "trash" }) : "%^GREEN%^You look over the weeds and trash but find little of interest.  The weeds have grown up in the exposed courtyard.  Likely brought there though the work of the many birds you can hear nesting through out the building.%^RESET%^",
	({ "booths", "colorful booths", "booth" }) : "%^GREEN%^You see evidence of only one of the many colored booths that once occupied this courtyard.  No doubt, the majority of them were carried away by their owners back when the Arena closed, but this one remaining booth was the healer's booth, at least that's your best guess from what you can tell of the broken wreck its become.%^RESET%^",
	({ "gate", "warrior's gate", "warrior gate", "warriors gate" }) : "%^BOLD%^%^RED%^This wrought iron gate is huge and serves as the entry way to the sand lined arena.  The depiction of two huge men locked in epic combat can be seen on the gate.  The image so detailed that you can see where the artist showed cuts in the warrior's bodies, and the spills of blood upon the earth.  Unfortunately, one of the hinges has given way, causing the gate to twist and fall open partway.  Enough for you to scramble over, if you wanted to access the arena.%^RESET%^",
	"arena" : "%^BOLD%^%^BLACK%^The huge granite stones that were used to form the arena and seating area have started to crumble and you can see where the mortar has flaked away, causing you to wonder how long it will be before this structure gives way completely.  Once a magnificent building its collapse took a large part of Seneca's tourism with it.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/arena_04",
		"northeast" : "/d/av_rooms/lurue/arena_03",
		"west" : "/d/av_rooms/lurue/arena_01",
		"east" : "/d/av_rooms/lurue/arena_05",
	]));

}