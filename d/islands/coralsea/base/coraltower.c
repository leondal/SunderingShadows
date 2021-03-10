#include <std.h>
#include "../defs.h"
inherit BASE"coralfun";

// Coral Sea Area - Created January 2009 by Ari
// Is inherited by all coral_b1-b9.c files

void pick_mon();

void create(){
    pick_mon();
    set_repop(10);
	::create();
		set_property("light",1);
		set_property("indoors",0);
		set_property("no teleport",1);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
	
		set_name("underwater tower");
		set_short("%^RESET%^%^CYAN%^An %^BOLD%^%^BLUE%^U%^RESET%^"+
			"%^CYAN%^n%^BOLD%^%^BLUE%^de%^BLACK%^r%^RESET%^%^BLUE%^w"+
			"%^BOLD%^at%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^r %^RESET%^"+
			"%^CYAN%^Tower%^RESET%^");
	
		set_long("%^RESET%^%^CYAN%^There is little left to this once "+
			"plushly appointed room.  Any %^ORANGE%^furniture %^CYAN%^or "+
			"%^WHITE%^adornments %^CYAN%^have long since fallen to the "+
			"remains of the floor, ruined beyond recognition into a pile "+
			"of %^GREEN%^algae %^CYAN%^coated rubble.  A few small "+
			"%^WHITE%^fish %^CYAN%^have made their home amongst the "+
			"remains, and you see at least one %^RED%^crustacean %^CYAN%^"+
			"vanish into a hole when you approach.%^RESET%^");
	
		set_smell("default","\nThere is nothing to smell under the water.");
		set_listen("default","You hear your air bubbling away.");
	
		set_items(([
			({"furniture","adornments"}):"%^RESET%^%^ORANGE%^There is "+
				"not much left of the furniture or personal items that "+
				"once made up this room's decorations.  Most has been "+
				"destroyed by water and time, though there are a few "+
				"instances where you see the hand of man having "+
				"interfered, including the lack of anything valuable.",
			
			({"algae","fish"}):"%^RESET%^%^GREEN%^Tiny fish dart in and "+
				"out of the many hideaways that have been created by "+
				"the room's rubble.  They flit about, nibbling on the "+
				"algae that grows thickly on almost everything in the "+
				"room.%^RESET%^",
			
			({"crustacean"}):"%^RESET%^%^RED%^Little crabs and lobsters "+
				"make their homes in the small niches that can be found "+
				"throughout the rubble.",

			({"water","ocean","sea","waters"}):"%^BOLD%^%^BLUE%^The water "+
				"stretches all around you, filing your vision with its "+
				"emptiness.  Maybe you should think about returning to "+
				"your boat before you're swept too far away.%^RESET%^",
		]));
		

}

void pick_mon(){
	int monsters;
	monsters = has_mobs();
	if(!monsters){
		if(mons){ mons = ([]); }
			switch(random(100)){
			case 0..10:   
				set_monsters(({MON"coral_fish.c"}),({random(2)+1}));
				monster_party(2);
			break;
			case 11..99:
			break;
		}
	}

	return 1;
}