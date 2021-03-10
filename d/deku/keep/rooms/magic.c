#include <std.h>
#include "../keep.h"

inherit VAULT;  

int searched;

void create() {
	::create();
	set_light(2);
	set_indoors(1);
	set_short("%^YELLOW%^Ruined Alchemy Shop%^RESET%^");
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_name("ruined alchemy shop");
	set_long("What was once a thriving alchemist shop is now %^BLUE%^debris%^RESET%^ laden, "+
		"by the looks of it this building was gutted rather forcefully.  The floor is littered with "+
		"broken %^MAGENTA%^shelves%^RESET%^ and shattered %^BLUE%^vials%^RESET%^.  Strangely there "+
		"is no visible blood and the air here does not hang heavy with decay.  A %^GREEN%^sign"+
		"%^RESET%^ remains intact on the northern wall.  There is a massive %^BOLD%^%^WHITE%^metal "+
		"door%^RESET%^ inset into the western wall.");
	set_smell("default","The room is filled with mingled smells of various herbs and concoctions.");
	set_listen("default","An occassional shout echoes through the keep.");
	set_exits(([  "east": KEEPR + "keepE4", "west" : KEEPR + "magicvault"]));
	set_items(([
		({"sign","Sign"}) : "The alchemist shop is now closed by order of Lord Hawk.",
		({"debris","Debris"}) : "Debris from broken shelves and shattered vials litter the floor here.",
		({"shelves","Shelves"}) : "All the shelves that were once used for display and storage of vials now lie fragmented on the floor of this room.",
		({"vials","Vials"}) : "The pieces of broken vials litter the floor here, all of their contents have long since evaporated.",
		({"Floor","floor"}) : "The floor of this room is littered with fragments of shelves and pieces of vials.",
		] ));
	set_search("default","How about trying to search through the debris?");
	set_search("debris",(:this_object(),"debris_search":));
	set_search("floor",(:this_object(),"debris_search":));
	set_search("vials",(:this_object(),"debris_search":));
	set_search("shelves",(:this_object(),"debris_search":));
	set_door("vault door",KEEPR + "magicvault","west","vault key","lock");
	set_string("vault door", "open", "%^BOLD%^%^WHITE%^The massive metal door swings open with suprising ease.%^RESET%^");
	set_locked("vault door",1,"lock");
	lock_difficulty("vault door",200,"lock");
	set_door_description("vault door","%^BOLD%^%^WHITE%^This massive metal door is inset into the western wall of this room.  There is a %^RED%^red hawk%^BOLD%^%^WHITE%^ with a %^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^ background, painted on the front of it.%^RESET%^");
	set_trap_functions(({"vault door"}),({"poison"}),({"pick"}));
}

int debris_search(object ob) {
	object ob1;
	int find;
	tell_room(TO,TP->query_cap_name() + "%^RED%^ searches through the debris.%^RESET%^",TP);
	if(searched == 1) {
		write("%^RED%^Your search through the debris but find nothing of interest.%^RESET%^");
		return 1;
	}
	
	find = random(100);
	if(find > 85) {
		ob1 = SEARCH_D->do_found_object();
		write("%^RED%^You search through the debris and find " +ob1->query_short()+ "%^RED%^!%^RESET%^");
		searched = 1;
		ob1->move(TO);
		return 1;
	}
	write("%^RED%^You search through the debris but find nothing of interest.%^RESET%^");
	searched = 1;
	return 1;

}	

int poison(){	
	toggle_trap("vault door","pick","lock");
	TP->add_poisoning(roll_dice(4,10));
	TP->setPoisoner(TO);
	tell_object(TP,"%^BOLD%^%^GREEN%^Something sharps pricks your hand as you pick at the lock!%^RESET%^");
	TP->force_me("emote yells and jerks " + TP->query_possessive() + " hand back");
	return 1;	
}