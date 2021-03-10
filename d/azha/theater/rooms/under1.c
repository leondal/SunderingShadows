#include <std.h>
#include "../theater.h"
inherit UNDER;
int FLAG;
	void create(){ 
	::create();
	set_long("%^ORANGE%^Smooth sandstone blocks form the walls of the "+
		"understage area of the theater.  Carved from the foundation"+
		" of the theater, the understage area is where the real work of"+
		" the theater is done.  The wide spacious corridors allow for"+
		" plenty of room to move large objects to the stage.  Wooden "+
		"support beams transverse the ceiling of this area, granting "+
		"support to the theater above.  Large amounts of %^RESET%^dust"+
		"%^ORANGE%^ covers the walls and beams, giving the illusion that"+
		" this part of the theater has not been in use for decades. "+
		"A narrow ladder leads back up into the catwalk of the theater."+
		"  To the west a wide wooden platform is resting, covered with"+
		" dust.\n");
	add_item(({"platform"}),"%^YELLOW%^Crafted from wooden planks,"+
	" this wide platform once served as the means for the crew of "+
	"the theater to move large props and costumes up to the stage."+
	"  The platform looks beaten and worn, but still in solid shape."+
	"  Thick lengths of hemp rope rise up on either corner of the "+
	"platform.  On the right corner of the platform there are a series"+
	" of toothed gears.\n");
	add_item(({"gear","gears","rope","ropes"}),"%^BOLD%^%^BLACK%^Made "+
	"from iron, these toothed gears appear to serve as a way to raise"+
	" the platform up to the stage area.  A square shaped metal bar "+
	"juts out of one of the larger gears, looking bare and naked.  "+
	"It almost seems as if something is missing.\n");

	set_exits(([ "east" : ROOMDIR"under2",
			 "north" : ROOMDIR"under4",
			 "south" : ROOMDIR"under6",
			 "up" : ROOMDIR"nest",
	]));
}
void init(){
::init();
    	add_action("fit","fit");
	add_action("fit","replace");
}
int fit(string str){
      if(!present("hand crank",TP)) {
		tell_object(TP,"The platform seems to be missing "+
			"something to make it move.");
	return 0;
	}   
	if(str != "hand crank" && str != "handcrank" && str != "crank") 
      	return notify_fail("What is it you wish to fit?\n");
	
	tell_object(TP,"%^BOLD%^%^BLACK%^You fit the handcrank to"+
		" the gears and begin to turn it.\n\nThe platform start to"+
		" rise slowly\n\n\n\nThe platform comes to a halt,not wanting"+
		" to move another inch.  Luckily though you can manage to reach"+
		" the backstage from here now.");
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" places the handcrank"+
		" onto the gears and begins to turn it.\n\nThe platform starts to"+
		" rise slowly.\n\n\n\nThe platform comes to a sudden halt, not "+
		"wanting to move another inch.  Luckily though it seems you can "+
		"manage to reach the backstage from here now.",TP);
			add_exit(ROOMDIR"backstage","backstage");
                	FLAG = 1;
    	return 1;
}
void reset() { 
	::reset(); 
		FLAG=0; 
	return; 
}
