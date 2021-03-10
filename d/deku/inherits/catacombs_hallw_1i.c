//Hallway inherit for the hallways on the first 
//level of the catacombs of the dead area - Saide - 3/09
#include <std.h>
#include <daemons.h>
#include "forest.h"
#define SD "/d/common/daemon/randstuff_d"
inherit CROOM;
int searched, mob_type;
void create() 
{
	if(!mob_type) mob_type = 1;
	if(!random(2)) 
	{ 
		if(base_name(TO) != CAT_HW_F)
	  	{
			if(mob_type == 1) 
			{
				//these mobs might need a tweak (for exp, gold), but the idea is 
				//that these catacombs are crawling with
				//shit-tons of undead on the first and second floor
				//third and fourth floor are the cultists responsible
				//so if you change these numbers, please at least
				//send me a mail about it - Saide
		   		set_monsters(({DEKU_MON"ca_skeleton"}),({2 + random(2)}));
				set_monsters(({DEKU_MON"ca_babu"}), ({1 + random(3)}));
				set_monsters(({DEKU_MON"ca_ghoul"}), ({1 + random(2)}));
				set_monsters(({DEKU_MON"ca_juju"}), ({1 + random(2)}));
    				set_repop(55);
			}
			if(mob_type == 2)
			{
				set_monsters(({DEKU_MON"tomb_guardian"}), ({1}));
				set_monsters(({DEKU_MON"tomb_spirit"}), ({1 + random(2)}));
				set_repop(50);
			}
		}
	}
    	::create();
    	set_short("%^YELLOW%^An aging brick hallway%^RESET%^");
    	set_name("An aging brick hallway");
    	set_property("light",0);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	//an ancient catacombs littered with all kinds of junk
	//making it possible that there are sticks sometimes
	if(!random(2)) 
	{
    		set_property("no sticks",1);
	}

set_long("%^YELLOW%^This ancient tunnel was hastily "+
	"thrown together with %^RED%^bricks%^RESET%^%^YELLOW%^ "+
	"of all sizes.  It is at "+
	"least a small wonder how the place has remained "+
	"standing for this long, as to top off the shoddy masonry "+
	"work, it has not aged well.  Their are %^MAGENTA%^enormous cracks"+
	"%^RESET%^%^YELLOW%^ "+
	"between most of %^RED%^bricks%^RESET%^%^YELLOW%^ and "+
	"%^MAGENTA%^dirt%^RESET%^%^YELLOW%^ almost literally pours "+
	"through wherever it finds an %^MAGENTA%^opening%^RESET%^%^YELLOW%^ "+
	"and all of the %^RED%^bricks%^RESET%^%^YELLOW%^ seem on "+
	"the verge of crumbling "+
	"at any moment, trapping you forever in this ancient "+
	"place.  The %^RED%^floor%^RESET%^%^YELLOW%^ and %^RED%^"+
	"ceiling%^RESET%^%^YELLOW%^ have decayed to the point "+
	"where it is no longer possible to tell what "+
	"they were originally made from.  All around you "+
	"there are huge piles of %^MAGENTA%^debris%^RESET%^%^YELLOW%^, most of which are "+
	"bones and appear to be human.%^RESET%^");
  
     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dust and decay, making "+
	"it hard to breath.");    
    	set_items(( [
		({"brick", "bricks"}) : "%^RED%^The bricks that complete the "+
		"structure of this hallway have fallen into grave disarray.  "+
		"They are almost all on the verge of crumbling and massive "+
		"cracks are evident throughout all of them, exposing the earth "+
		"beyond.%^RESET%^", 
		({"dirt", "earth"}) : "%^MAGENTA%^The earth that hides "+
		"these catacombs is evident beyond the cracks in the bricks, "+
		"and far too much of it has even managed to spill into the "+
		"hallway.%^RESET%^", 
		({"floor", "ceiling"}) : "%^RED%^The floor and ceiling "+
		"of this place have decayed to the point where you can no "+
		"longer tell what they were originally made from.  It may "+
		"very well have been the same type of bricks that compose the "+
		"rest of this structure, either way, you have no doubt that "+
		"it is not safe to be walking down here.%^RESET%^", 
		({"crack", "cracks", "opening", "enormous cracks"}) : "%^MAGENTA%^"+
		"Enormous cracks are evident between and actually on all of the "+
		"bricks in this structure, they provide openings through which "+
		"dirt seems to almost continually pour through.  You wonder "+
		"how this place is evening standing and not tumbling down on "+
		"top of you.%^RESET%^",
		({"debris", "piles of debris"}) : "%^MAGENTA%^Piles of debris "+
		"are thrown about down here casually and you are unsure of how "+
		"they got here.  Unfortunately most of them appear to be bones, "+
		"human bones, however, there is the occassional stick and piece "+
		"of rock, and some other, unidentifiable things.",
     	] ));

set_search("default", "%^MAGENTA%^You wonder cautiously if there "+
	"might be something of value hidden within the %^RED%^debris%^RESET%^"+
	"%^MAGENTA%^.%^RESET%^");
	searched = random(2);
	set_search("debris", (:TO, "debris_search":));
}

void reset()
{
	::reset();
	searched = random(2);
}

int debris_search() 
{
	if(!TP->query_invis()) 
	{
      	tell_room(TO,TPQCN+"%^BOLD%^%^WHITE%^ digs through a pile "+
		"of debris, tossing some human bones out of "+TP->QP+ " way!%^RESET%^",TP);
    	}
	tell_object(TP,"%^BOLD%^%^WHITE%^You dig through a pile "+
    	"of debris, tossing some human bones out of your way.%^RESET%^");
    	if(searched == 0 && !random(5)) 
	{
       	tell_object(TP,"%^BOLD%^%^RED%^Your search turns up something "+
        	"of value.%^RESET%^");
        	if(!TP->query_invis()) 
		{
            	tell_room(TO,TPQCN+"%^BOLD%^%^RED%^ finds something of value "+
            	"hidden in the debris.%^RESET%^",TP);
        	}
       	SD->find_stuff(TO,"random");
        	searched = 1;
        	return 1;
    	}
    	tell_object(TP,"%^BOLD%^%^WHITE%^You give up the search after "+
    	"digging through the debris and finding nothing of value.%^RESET%^");    

	if(!TP->query_invis()) 
	{
      	tell_room(TO,TPQCN+"%^BOLD%^%^RED%^ seems to find nothing of "+
        	"interest in the debris.%^RESET%^",TP);
    	}

    	searched = 1;
    	return 1;
}
