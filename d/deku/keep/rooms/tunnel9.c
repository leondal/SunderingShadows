#include <std.h>
#include "../keep.h"
#define CORPSE_ITEMS ({"corpse","rotting corpse","mangled corpse","human corpse","remains",\
"rotting remains","mangled remains"})
#define R_WALL_ITEMS ({"rock","south wall","rock wall"})
inherit TUNNEL;
int found;

void create() {
	int x;
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  The southern wall of this tunnel is made from "+
		"solid %^BOLD%^%^WHITE%^rock%^YELLOW%^.  The mangled %^RED%^corpse%^YELLOW%^ "+
		"of what could have been a human is leaning against the %^BOLD%^%^WHITE%^rock wall"+
		"%^YELLOW%^.  The tunnel continues into %^BOLD%^%^BLACK%^darkness%^YELLOW%^ to the north.%^RESET%^");
    set_exits(([
		"north": KEEPR + "tunnel8"
    ] ));
	
	set_climb_exits((["climb":({ KEEPR+"tunnel10",20,6,100})]));
 set_fall_desc("%^RED%^You fall about 20 feet, landing in the foul smelling fluid in this "+
					"tunnel with a loud splash!%^RESET%^");

	for(x = 0;x < sizeof(R_WALL_ITEMS);x++) {
	add_item(R_WALL_ITEMS[x],"%^BOLD%^%^WHITE%^This wall is made from solid rock, with the proper "+
		"tools or knowledge you might be able to climb it and get out of here.%^RESET%^");
	}	

	for(x = 0;x < sizeof(CORPSE_ITEMS);x++) {
	add_item(CORPSE_ITEMS[x],"%^BOLD%^%^RED%^The remains of this man show that his death was not a "+
		"peaceful one.  Several of the visible bones are twisted and broken, obviously by some "+
		"powerful force.  The flesh that remains has been ravaged by slashing wounds.  A foul "+
		"odor is given off from the corpse, it has been here for some time.  You are unsure if "+
		"anything of value remains on it, to know you would have to completely %^RESET%^"+
		"search%^BOLD%^%^RED%^ it.%^RESET%^");
	}

	set_search("default","The corpse looks interesting.");
	set_search("corpse",(:this_object(),"corpse_search":));
	set_search("remains",(:this_object(),"corpse_search":));
}

void corpse_search() {
	if(!TP->query_invis()) {
	tell_room(TO,TP->query_cap_name() + "%^RED%^ digs through the %^BLUE%^rotting remains%^RED%^"+
		".%^RESET%^",TP);
	}
	if(found == 1) {
		tell_object(TP,"%^RED%^You dig through the %^BLUE%^rotting remains%^RED%^ of the corpse but "+
			"find nothing you would consider keeping.%^RESET%^");
		return;
	}
	else {
		found = 1;
		new("/d/common/obj/misc/climb_tool")->move(TO);
		new(KEEPO + "journal3")->move(TO);
		tell_object(TP,"%^RED%^You dig through the %^BLUE%^rotting remains%^RED%^ of the corpse and "+
			"find a %^BOLD%^%^GREEN%^piece of parchment%^RESET%^%^RED%^ and some %^BOLD%^%^GREEN%^"+
			"climbing tools%^RESET%^%^RED%^!%^RESET%^");
		return;
	}

}