#include <std.h>
#include "../defs.h"
inherit BASE"coralwreck";

// Coral Sea Area - Created January 2009 by Ari

void init(){
	::init();
		add_action("peer_around","peer");
		add_action("find_tear","tear");
		add_action("find_tear","enlarge");
}

void create(){
	::create();
		set_long(::query_long()+"%^RESET%^%^ORANGE%^A piece of mast lays "+
			"over the top wrapped in some of the %^GREEN%^emerald green "+
			"%^ORANGE%^canvas that once sailed this ship.  The canopy "+
			"creating an unnatural %^BOLD%^%^BLACK%^cave %^RESET%^"+
			"%^ORANGE%^deep within the cold ocean.  Though most of the "+
			"ship appears shorn away, a wooden door provides access to "+
			"somewhere deeper in the ship.  Whether the area beyond "+
			"survived whole or not, is uncertain.%^RESET%^");  
		
		add_item(({ "canvas", "cloth", "sails", "canopy" }),"%^RESET%^"+
			"%^GREEN%^The thick cloth must be well made to have withstood "+
			"what has happened to the ship already. Though you can see "+
			"tears and rips here and there. The remains of the mast "+
			"keep it pinned down, creating the small cave like area "+
			"where you stand.  You think though, given a bit of effort "+
			"you might be able to enlarge one of the tears.%^RESET%^");
	
		set_exits(([
			"northeast":ROOMS"coral_b9",
			"east":ROOMS"coral_w1",
		]));
		
		set_door("door",ROOMS"coral_w1","east","cskeyriin");
		set_door_description("door","%^RESET%^%^CYAN%^The door is heavily "+
                "made and is reinforced with iron bands.  You're sure this "+
				"is why it is still whole and functioning despite the "+
				"wrecked state of the ship.%^RESET%^");
		set_locked("door",1);
		lock_difficulty("door",-70,"lock");          
		set_string("door","open","%^BLUE%^The door opens and several %^WHITE%^"+
			"bubbles %^BLUE%^rush out!%^RESET%^\n");

}


int find_tear(string str){
    if((str == "sail") || (str == "tear") || (str == "canvas")){
        if(member_array("hole",TO->query_exits()) != -1) {
             tell_object(TP,"%^GREEN%^The sail has already been "+
				"removed!%^RESET%^");
            return 1;
            }
		tell_object(TP,"%^BOLD%^%^GREEN%^You struggle to lift a "+
			"piece of the heavy canvas sail, but manage to make a "+
			"small hole you can swim through!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^GREEN%^A bit of canvas tears "+
			"open, revealing a small hole you can swim through!"+
			"%^RESET%^",TP);
		add_exit(ROOMS"coral_w3","tear");
    return 1;
    }
		
}

int peer_around(string str){
	tell_object(TP,"You can't seem to see anything through the hazy, "+
		"coral dust filled water.");
	return 1;
}

void reset(){
	::reset();
		remove_exit("coral_w3");
		tell_room(TO,"%^BOLD%^%^CYAN%^The current shifts, "+
			"resettling the canvas.%^RESET%^");
}