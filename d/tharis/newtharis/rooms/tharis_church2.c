#include <std.h>
#include "../tharis.h"
inherit "/std/church";

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Church Remodle - Created in February 2009 by Ari

/* Author's note: This room is meant to accomplish two 
things.  The first is to provide a meeting room for player 
use that is somewhat removed.  As it was agreed that 
most of old Tharis' underground tunnels were superfluous
and unneeded, we removed them.  However, the city is 
a thief city so having a couple hidden rooms seemed
like a good idea.  
The second reason is I felt there should be a way
to access the underground roadways (Nienne/Ari's 
project).  This room's design is meant less for meetings
and more for laying bodies out for viewing.  Then, 
through manipulating a lever in the lanterns, a panel
could be opened to access the catacombs and eventually
the underground pathways.  I felt the church was the
most logical as players may revive in them after death
and this would give a pathway out for "beast races". */

void create(){
	::create();
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		set_property("no sticks", 1);
		set_property("light",2);
		set_property("indoors",1);
		
		set_name("Basement of the Tharis Cathedral");
        set_short("%^YELLOW%^Basement of the Tharis "+
			"Cathedral%^RESET%^");
        set_long("%^YELLOW%^Basement of the Tharis "+
			"Cathedral%^RESET%^\n"
			"%^RESET%^Unlike the Cathedral above, this basement "+
			"is rather simple and unadorned.  %^ORANGE%^Wood "+
			"paneling%^RESET%^ has been put up over the stone "+
			"walls and the floor has been lined with a thick "+
			"%^BOLD%^%^BLACK%^gray%^RESET%^, %^BOLD%^%^WHITE%^"+
			"white %^RESET%^and %^ORANGE%^brown %^RESET%^rug.  "+
			"Hung from the walls are evenly spaced lanterns that "+
			"glow with a soft, magical %^BOLD%^%^WHITE%^ light"+
			"%^RESET%^. A large, low %^ORANGE%^table %^RESET%^has "+
			"been pushed to the side of the room and several "+
			"comfortable looking, straight back %^ORANGE%^chairs "+
			"%^RESET%^are lined up along the other side, "+
			"suggesting this room is used as a meeting place from "+
			"time to time.  Otherwise there is nothing much of "+
			"interest.%^RESET%^");
		
		set_smell("default","Sweet incense tickles you nose.");
		set_listen("default","It is quiet here in the basement.");
		
        set_items(([
			({"walls","wood panels","panels","stone"}):"%^RESET%^"+
				"%^ORANGE%^The stone walls of the basement have been "+
				"covered in thin sheets of warm colored wood, making "+
				"this mostly empty chamber more comfortable and less "+
				"stark.  Seamlessly fitted together, it would be "+
				"almost impossible to tell that the walls are actually"+
				"made of stone.%^RESET%^",
			({"rug","floor"}):"%^RESET%^The thick rug softens footfalls "+
				"and muffles the room considerably, making it nearly "+
				"silent here.  A blending of %^ORANGE%^brown%^RESET%^, "+
				"%^BOLD%^%^WHITE%^white %^RESET%^and %^BOLD%^%^BLACK%^ "+
				"gray%^RESET%^ threads gives it a neutral, pleasant "+
				"appearance.",
			({"lanterns"}):"%^BOLD%^%^BLACK%^Made from sheets of dark "+
				"iron, the lanterns are hung from evenly spaced hooks "+
				"along the wall.  A soft %^WHITE%^white%^BLACK%^ light "+
				"glows within each, suggesting magical light rather "+
				"candle light.%^RESET%^",
			({"table"}):"%^RESET%^%^ORANGE%^The table is surprisingly "+
				"low, and would not be the most comfortable for "+
				"sitting at. Although some of the smaller races might "+
				"consider it the perfect height.  Set against one of "+
				"walls, the table is extra thick and very strudy, "+
				"which also makes it rather heavy.  The only thing "+
				"this table would be very good for would be if "+
				"everyone was standing around it and looking down at "+
				"something lain out on it.%^RESET%^",
			({"chairs"}):"%^RESET%^%^ORANGE%^Each of these high backed "+
				"chairs are simple in design. They have cushions both "+
				"on the seat and the back of each chair.  The fabric "+
				"a dull fawn shade that blends into the polished wood "+
				"and doesn't draw the eye especially.  One could sit "+
				"in such a chair for a while without getting stiff or "+
				"sore.%^RESET%^",
		]));
        
		set_exits(([
                "stairs":ROOMS"tharis_church1"
        ]));
		set_search("default","%^BOLD%^%^BLACK%^What did you want to search?%^RESET%^");
		set_search("lanterns",(:TO,"search_lanterns":));
}

int search_lanterns(string str){
	object ob;
	if(str == "lanterns" || str == "lantern"){
		tell_object(TP,"%^BOLD%^%^BLACK%^Finding a loose lantern you give "+
			"it a pull.  One of the panels slides to the side, revealing a "+
                        "hallway leading to a tunnel.%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" pulls on one "+
			"of the lanterns and causes a panel to the side.%^RESET%^",TP);
                add_exit(ROOMS"tunnel1","down");
		return 1;
	}
}

void reset(){
	::reset();
   if(member_array("down",TO->query_exits()) != -1) {
     tell_room(TO,"%^RESET%^%^ORANGE%^The panel slides back into place, hiding the tunnel from view.%^RESET%^");
     remove_exit("down");
   }
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}