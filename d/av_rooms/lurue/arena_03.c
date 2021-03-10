// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_03");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RED%^The abandoned halls of the Seneca Arena%^RESET%^");

    set_long("%^RESET%^The remains of stone benches rise up in a steep multistory edifice that once served as spectator seats for the %^YELLOW%^Seneca Arena%^RESET%^.  Now, they are little more then %^GREEN%^weed %"
	"^RESET%^and %^BOLD%^%^BLACK%^trash %^RESET%^lined ruins, the benches have begun to crumble under the pressure and attention of the %^GREEN%^weeds %^RESET%^and %^CYAN%^weather%^RESET%^.  Once these sea"
	"ts gave a perfect view of the sand-lined arena, in fact they still do.  Peering over the iron railing, you can see the vast area of the arena floor, including the entry into the gladiator's lounge on "
	"the eastside.  The place where famed warriors rested and were tended between their battles.%^RESET%^"
	);

    set_smell("default","
Dust and rot tingle your nose.");
    set_listen("default","The coo and chirp of nesting birds reaches you once in a while.");

    set_search("trash","%^BOLD%^%^BLACK%^You search around in the trash and find a notice for an upcoming battle between %^RED%^Aouton the Red%^BLACK%^ and someone called %^RESET%^%^GREEN%^Swrindri the Green%^BOLD%^%^BLACK%^.  The battle was scheduled for 20 Sundays, 601 SG at third bell.%^RESET%^");
    
set_items(([ 
	({ "gladiators lounge", "gladiator's lounge", "lounge" }) : "%^RESET%^%^ORANGE%^You can't make out much about what is beyond the iron gate.  All you can see is a set of stairs leading down into the earth.%^RESET%^",
	"sand" : "%^RESET%^%^ORANGE%^You can see that the arena's pit is filled with what was probably very fine sand.  Something that would have cushioned and supported the gladiators in their combat.  However, after years of rains, even the bloodstains have been washed away and the ground is caked and hard.  Completely unsuited for such a spectator sport. %^RESET%^",
	({ "benches", "seats", "bench", "seat" }) : "%^BOLD%^%^BLACK%^The benches were probably never all that comfortable, but then, its likely that most didn't sit on them for long anyway.  The bloody battles that happened in the arena often had fans standing and cheering.  The benches appear designed for utility and for ware.  Unfortunately, due to disuse the whole place seems to be crumbling away.  Seats included.%^RESET%^",
	({ "weeds", "trash" }) : "%^GREEN%^You look over the weeds and trash but find little of interest.  The weeds have grown up in the exposed courtyard.  Likely brought there though the work of the many birds you can hear nesting through out the building.%^RESET%^",
	"arena" : "%^BOLD%^%^BLACK%^The huge granite stones that were used to form the arena and seating area have started to crumble and you can see where the mortar has flaked away, causing you to wonder how long it will be before this structure gives way completely.  Once a magnificent building its collapse took a large part of Seneca's tourism with it.%^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/arena_02",
	]));

}