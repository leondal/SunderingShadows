#include <std.h>
#include "../keep.h"     
inherit VAULT;
#define POTIONS ({ "cure_poison","heal","paralyze","poison","hurt","extra_heal","invisible",\
	"det_invis","hurt","weaken", "cure_poison","heal","paralyze","poison","hurt","weaken","heal",\
 "poison","hurt","paralyze","poison","cure_poison","extra_heal","poison","hurt","raging_heal",\
"poison","hurt","paralyze","hurt","weaken","invisible" })

int searched;

void create() {
	::create();
	set_light(2);
	set_indoors(1);
	set_property("no teleport",1);
	set_name("alchemy vault");
	set_short("%^BOLD%^%^WHITE%^Alchemy Vault%^RESET%^");
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_long("%^BOLD%^%^WHITE%^This small chamber is made from solid %^BOLD%^%^BLACK%^"+
		"metal%^BOLD%^%^WHITE%^, obviously a type of well protected storage area.  However, it is "+
		"suprisingly empty, the %^RED%^floor%^BOLD%^%^WHITE%^ is completely clean, even lacking "+
		"any particles of dust.  The only piece of furniture in this room is a %^MAGENTA%^table"+
		"%^BOLD%^%^WHITE%^, which stands almost directly in the center of the room.  The top of the "+
		"table is covered with %^BOLD%^%^BLUE%^vials%^BOLD%^%^WHITE%^, filled with different "+
		"colored liquids.  There is a door inset into the eastern wall of this room.%^RESET%^");
	set_smell("default","A sweet odor lingers in the air here.");
	set_listen("default","A strange silence fills this room");
	set_exits(([  "east": KEEPR + "magic"]));
	set_items(([
		({"Floor","floor"}) : "The floor of this room is made from a solid %^BOLD%^%^WHITE%^"+
		"metal%^RESET%^, strangely, it is completely bare, except for the table resting in the "+
		"center of it.%^RESET%^",
		({"table","Table"}) : "This table rest in the center of the room and is covered with "+
		"%^BOLD%^%^BLUE%^vials%^RESET%^ of diffent colored liquids.",
		({"vials","vial","Vials","Vial"}) : "%^BOLD%^%^BLUE%^These vials cover the top of the table "+
		"in the center of this room.%^RESET%^",
		] ));
	set_search("default","How about searching through the vials?");
	set_search("vials",(:this_object(),"vial_search":));
	set_search("vial",(:this_object(),"vial_search":));
	set_door("vault door",KEEPR + "magic","east","vault key","lock");
	set_string("vault door", "open", "%^BOLD%^%^WHITE%^The massive metal door swings open with suprising ease.%^RESET%^");
	set_locked("vault door",1,"lock");
	lock_difficulty("vault door",200,"lock");
	set_door_description("vault door","%^BOLD%^%^WHITE%^This massive metal door is inset into the eastern wall of this room.  There is a %^RED%^red hawk%^BOLD%^%^WHITE%^ with a %^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^ background, painted on the front of it.%^RESET%^");
	searched = 0;
}

void do_choose_potion(object where) {
	int x;
	x = random(sizeof(POTIONS));
	return new("/d/common/obj/potion/" + POTIONS[x])->move(where);
}

void reset() {
	::reset();
	if(random(6) == 3) {
		searched = 0;
	}
}

void vial_search() {
	int i, x, how_many;
	
	i = random(100);
	tell_room(TO,TPQCN+" examines the vials carefully.",TP);
 if(i >= 20 && i <= 80) {
	if(searched == 1) {
			write("You search through the vials, but find none that are of any value.");
			return;
		}
		else {
			searched = 1;
			how_many = random(3) + 4;
			for(x = 0;x < how_many;x++) {
				do_choose_potion(TO);
			}
			write("You search through the vials and find " + how_many + " that you might be able to "+
				"use!");
			return;
		}
	}
	else {
		searched = 1;
		return write("You search through the vials and find none that are of any value.");
	}
	
}

