#include <std.h>
#include "../defs.h"
inherit BASE"coralwreck";

// Coral Sea Area - Created January 2009 by Ari

init(){
	::init();
		add_action("go_east","east");
		add_action("go_east","e");
		add_action("insert_compass","insert");
		add_action("insert_compass","fit");
}

void create(){
	::create();
	
	set_long("%^RESET%^%^ORANGE%^Before you stretches a large garden "+
		"of %^GREEN%^kelp%^ORANGE%^.  Once a hedge maze, now all that "+
		"%^BOLD%^%^BLACK%^fertile soil %^RESET%^%^ORANGE%^and "+
		"%^RESET%^wall structure %^ORANGE%^serves as a perfect "+
		"growing area for the garden of the sea.  Here, some damage "+
		"has been done to the large kelp bed, as the remains of a "+
		"broken ship lay here wedged up against the towering %^BOLD%^"+
		"%^BLACK%^structure%^RESET%^%^ORANGE%^.  Snapped in two by "+
		"the force of the sea when it went down, you can now view "+
		"part of the ship's hull, though an inner %^RESET%^bulkhead "+
		"%^ORANGE%^prevents you from seeing much.  Painted onto the "+
		"bulkhead's wall is a curious symbol.  An %^GREEN%^emerald "+
		"compass rose %^ORANGE%^with a %^YELLOW%^brass ring "+
		"%^RESET%^%^ORANGE%^in its center, almost as if something "+
		"fits there.  Draping down over part of the remains are the "+
		"torn and tattered sails of the ship.  Their faded %^GREEN%^"+
		"green %^ORANGE%^color no match for the brilliance of the "+
		"compass rose.%^RESET%^");
		
		add_item(({"soil","wall","kelp","garden"}),"%^RESET%^%^GREEN%^"+
			"The kelp has grown up thick here, claiming what was once "+
			"an intricate hedge maze.  Now, the low stone walls have "+
			"crumbled away leaving large stones for the kelp to cling "+
			"to with their holdfasts, while the fertile soil that "+
			"still remains below a layer of sea silt, provides a "+
			"healthy growing ground for the kelp.%^RESET%^");
		
		add_item(({"bulkhead","wall"}),"%^RESET%^The bulkhead is a "+
			"part of the ship which creates chambers within the "+
			"lower holds.  This helps seal off sections of the ship "+
			"in the case of a breech and can be the difference "+
			"between whether or not a ship sinks or not.  Usually "+
			"there is some means to pass through them, a door or "+
			"other device, but in this case it would seem the "+
			"bulkhead was designed without a door.");
			
		add_item(({"compass rose","rose","ring","brass ring"}),""+
			"%^GREEN%^The symbol is like a eight-pointed starburst "+
			"with each point directed toward a cardinal point.  "+
			"Painted onto the bulkhead there are swirls of varying "+
			"shades of green, accented with highlights of gold and "+
			"black to give it contrast.  In the center of this "+
			"design is a fist sized brass ring. All around the ring "+
			"a series of lines have been marked, twenty-one in all "+
			"though their meaning is uncertain.  You think though, "+
			"that something might fit into the ring, but what could "+
			"that be?  And, more important, what would it do if you "+
			"found it? %^RESET%^");
	
		set_exits(([
			"west":ROOMS"coral_m24",
		]));
}

int go_east(string str){
	tell_object(TP,"The sail tangles up and prevents your "+
		"passage that way.");
	return 1;
}

int insert_compass(string str){
	object obj;
	if(str != "compass"){
		tell_object(TP,"%^YELLOW%^What did you want to insert?%^RESET%^");
	return 1;
	}
	if(!present("cscompriin",TP)){
		notify_fail("Insert what?\n"); 
	return 0;
	}

		tell_room(ETP,"%^BOLD%^%^GREEN%^As the compass is "+
			"fitted into place, the metal sliver within begins to "+
			"swing back and forth wildly.%^RESET%^"); 
		tell_room(ETP,"%^BOLD%^%^CYAN%^It whirls round.. "+
			"%^BLUE%^and round.. %^RESET%^%^BLUE%^and round..%^RESET%^"); 
		tell_room(ETP,"%^BOLD%^%^GREEN%^Here and there it "+
			"stops its wild spinning for a moment only to resume "+
			"once more almost immediately."); 
		tell_room(ETP,"%^BOLD%^%^BLUE%^Suddenly you feel "+
			"the water stir as the painting becomes unsubstantial."+
			"%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^GREEN%^You realize that "+
			"a new passage has opened through the bulkhead!");
		add_exit(ROOMS"coral_w4","passage");
		
		obj = present("cscompriin",TP);
		obj->remove();

	return 1;
}

void reset(){
	::reset();
		remove_exit("coral_w4");
		tell_room(TO,"%^BOLD%^%^GREEN%^The portal flickers and "+
			"then vanishes, leaving only the painted symbol "+
			"behind.%^RESET%^");
}