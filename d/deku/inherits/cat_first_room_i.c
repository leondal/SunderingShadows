#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
#define SD "/d/common/daemon/randstuff_d"
inherit ROOM;
int door_opened, which_room, searched;
string direc, direc2, direc_exit;
void create() 
{
    	::create();
    	set_short("%^BOLD%^%^RED%^A massive brick chamber%^RESET%^");
    	set_name("A massive brick chamber");
    	set_property("light",0);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	set_property("no sticks", 1);
	door_opened = 0;
	if(!which_room)
	{
		which_room = 1;
	}
	switch(which_room) 
	{
		case 1:
			direc = "south";
			direc2 = "north";
			direc_exit = CAT_ROOMS"cat_first_sr_1";
			break;
		case 2:
			direc = "north";
			direc2 = "south";
			direc_exit = CAT_ROOMS"cat_hw_first_13";
			break;
		case 3:
			direc = "south";
			direc2 = "west";
			direc_exit = CAT_ROOMS"cat_first_sr_2";
			break;
		case 4:
			direc = "north";
			direc2 = "east";
			direc_exit = CAT_ROOMS"cat_first_sr_3";
			break;
	}


set_long((:TO, "long_desc":));

     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");

    	set_smell("default","The air is heavy with dust and decay, making "+
	"it hard to breath.");    

    	set_items(( [
		({"bricks", "dark red bricks", "red bricks"}) : "%^RED%^"+
		"These bricks look ancient, however, they have gracefully "+
		"withstood the test of time.  Strangely, %^BOLD%^%^BLUE%^"+
		"magical glyphs%^RESET%^%^RED%^ have been inscribed onto "+
		"all of them.%^RESET%^", 
		({"glyphs", "magical glyphs"}) : (:TO, "glyphs_desc":), 
		({"pattern", direc+" wall"}) : (:TO, "pattern_desc" :),
		({"debris", "piles of debris"}) : "%^MAGENTA%^Piles of debris "+
		"are thrown about down here casually and you are unsure of how "+
		"they got here.  Unfortunately most of them appear to be bones, "+
		"human bones, however, there is the occassional stick and piece "+
		"of rock, and some other, unidentifiable things.%^RESET%^",
     	] ));

      set_search("default", "%^MAGENTA%^You wonder cautiously if there "+
	"might be something of value hidden within the %^RED%^debris%^RESET%^"+
	"%^MAGENTA%^.%^RESET%^");
	searched = random(2);
	set_search("debris", (:TO, "debris_search":));
}

void init() 
{
  	::init();
	add_action("trace_action","trace");
	if(!present("tomb guardian")) return;
	present("tomb guardian", TO)->force_me("block "+direc2);
}

int trace_action(string str)
{
	if(!objectp(TP)) return 0;
	if(door_opened == 1) return 0;
	if(!str && str != "pattern" && str != "the pattern")
	{
		tell_object(TP, "%^CYAN%^Perhaps you might try tracing the "+
		"%^BOLD%^pattern%^RESET%^%^CYAN%^.%^RESET%^");
		return 1;
	}
	if(present("tomb guardian", TO)) 
	{
		tell_object(TP, "The Guardian prevents you from doing "+
		"that!");
		return 1;
	}
	tell_object(TP, "%^CYAN%^You walk up to the "+direc+" wall "+
	"and carefully %^BOLD%^trace the pattern%^RESET%^%^CYAN%^ "+
	"created by the magical glyphs!%^RESET%^");

	tell_room(TO, TPQCN +"%^CYAN%^ walks up to the "+direc+" wall "+
	"and carefully %^BOLD%^traces the pattern%^RESET%^%^CYAN%^ "+
	"created by the magical glyphs!%^RESET%^", TP);

	tell_object(TP, "%^CYAN%^As you finish tracing the pattern, "+
	"you realize that it was of a door and before you can respond "+
	"a section of the "+direc+" wall, where the pattern was, "+
	"fades away!%^RESET%^");

	tell_room(TO, "%^CYAN%^As "+TPQCN +"%^RESET%^%^CYAN%^ finishes "+
	"tracing the pattern, a section of the "+direc+" wall, where the "+
	"pattern was, fades away!%^RESET%^", TP);
	door_opened = 1;
	TO->add_exit(direc_exit, direc);
	return 1;
}

string glyphs_desc()
{
	if(door_opened == 0)
	{
		return "%^BOLD%^%^BLUE%^These strange magical glyphs "+
		"cover most of the walls of this chamber.  They seem "+
		"to attempt to portray some type of message, but "+
		"unfortunately you are unable to discern it.  "+
		"Strangely, they seem to be moving "+
		"in some type of %^BOLD%^%^CYAN%^pattern%^BOLD%^%^BLUE%^ "+
		"on the "+direc+" wall.%^RESET%^";
	}
	if(door_opened == 1)
	{
		return "%^BOLD%^%^BLUE%^These strange magical glyphs "+
		"cover most of the walls of this chamber.  They seem "+
		"to attempt to portray some type of message, but "+
		"unfortunately you are unable to discern it.%^RESET%^";
	}
}

void pattern_desc()
{
	if(door_opened == 1)
	{
		return "%^BOLD%^%^BLUE%^The pattern has faded, along "+
		"with the section of wall that it was on.%^RESET%^";
	}
	if(door_opened == 0)
	{
		return "%^BOLD%^%^BLUE%^The magical glyphs on the "+
		direc+" wall seem to be moving in some type of "+
		"%^BOLD%^%^CYAN%^pattern%^BOLD%^%^BLUE%^.  "+
		"You get the urge to %^BOLD%^%^CYAN%^trace"+
		"%^BOLD%^%^BLUE%^ it.%^RESET%^";
	}
}

void long_desc() 
{
	string tmp;
	tmp = "%^BOLD%^%^RED%^The massive chamber that you find yourself "+
	"in looks at least several centuries old.  It is composed entirely of "+
	"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ that have somehow, "+
	"miraculously, withstood the test of time.  The floor here is littered "+
	"with %^MAGENTA%^debris%^BOLD%^%^RED%^, most of which appear to be "+
	"human bones.  The walls of the "+
	"chamber have been almost entirely covered with "+
	"strange, ancient %^BLUE%^magical glyphs%^RESET%^%^BOLD%^%^RED%^ "+
	"that seem to portray some message, which, unfortunately "+
	"you fail to understand.%^RESET%^";
	if(door_opened == 0)
	{
		tmp += "%^BOLD%^%^RED%^  A section of the "+
		"%^RESET%^%^BOLD%^%^BLUE%^magical glyphs%^BOLD%^%^RED%^ "+
		"on the "+direc+" wall seems to be constantly moving "+
		"in some type of %^BOLD%^%^CYAN%^pattern%^BOLD%^%^RED%^."+
		"  A tunnel of bricks, which appears "+
		"far more worn and unstable, leads out of here to the "+
		direc2+".%^RESET%^";
	}
	if(door_opened == 1)
	{
		tmp += "%^BOLD%^%^RED%^  A section of the "+
		direc+" wall has disappeared, revealing an opening "+
		"into darkness.  A tunnel of bricks, which "+
		"appears far more worn and unstable, leads out of here "+
		"to the "+direc2+".%^RESET%^";
	}
	return tmp;	
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

void reset()
{
	::reset();
	searched = 0;
	if(!present("tomb guardian", TO)) 
	{
		new(DEKU_MON"tomb_guardian")->move(TO);
		door_opened = 0;
		TO->remove_exit(direc);
	}
}
