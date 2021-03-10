#include <std.h>
#include "../keep.h"

inherit ROOM;

int csearched, searched;

void create() {
	::create();
	set_property("light", 2);
	set_property("indoors", 1);
	set_name("ruined tavern");
	set_short("%^YELLOW%^Ruined Tavern%^RESET%^");
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_long("This large stone structure was once a successful tavern, but something dark has "+
		"ravaged it.  The floor of this building is littered with %^BOLD%^%^BLACK%^debris%^RESET%^ "+
		"ranging from broken %^BLUE%^tables%^RESET%^ to rotting %^RED%^corpses%^RESET%^.  Whatever "+
		"came through here left none alive.  A bloodstained %^RED%^menu%^RESET%^ is hanging on the "+
		"eastern wall.%^RESET%^");
	set_smell("default","A strong odor of decay with a hint of old ale lingers here.");
	set_listen("default","It is deathly quiet here..");
	set_search("default","Maybe you should try searching the debris? Or maybe you should turn over a corpse or two?");
	set_search("debris",(:this_object(),"debris_search":));
	set_search("tables",(:this_object(),"debris_search":));
	set_search("floor",(:this_object(),"debris_search":));
	set_search("corpses",(:this_object(),"corpse_search":));
	set_search("corpse",(:this_object(),"corpse_search":));
	set_items(
		([
		({"menu","Menu"}) : "%^RED%^This menu is stained with blood, its impossible to make out any "+
		"of the writing.%^RESET%^",
		({"debris","Debris"}) : "%^BOLD%^%^BLACK%^Various types of debris litter the floor of this "+
		"building.%^RESET%^",
		({"corpse","corpses","Corpse","Corpses"}) : "%^RED%^These fallen bodies are in varying "+
		"degrees of rot, all of them have been slain by claw like wounds.  Perhaps the work of "+
		"some massive wolf?%^RESET%^",
		({"Floor","floor"}) : "%^RED%^The floor of this building is littered with debris ranging "+
		"from broken tables to rotting bodies.%^RESET%^",
		({"Table","table","Tables","tables"}) : "%^RED%^All of the tables in this once thriving pub "+
		"have been rendered valueless.  Obviously the work of some very angry creature.%^RESET%^",
		]));
	set_exits( (["south" : KEEPR + "keepW1"]) );
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

int corpse_search(object ob) {
	object ob1;
	tell_room(TO,TPQCN+"%^RED%^ digs through the rotting corpses.%^RESET%^",TP);
	if(csearched == 1) {
		write("You dig through the rotting corpses but find nothing of value.\n");
		return 1;
	}
	else {
		write("You turn over one of the corpses and find a piece of parchment!\n");
		new(KEEPO + "journal1")->move(TO);
		csearched = 1;
		return 1;
	}
	
}
