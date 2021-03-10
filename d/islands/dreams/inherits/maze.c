#include <std.h>
#include "../defs.h"
inherit CROOM;
void pick_critters();

void create()
{
  
	pick_critters();
   	set_repop(35);
	::create();
	set_terrain(BARREN);
   	set_travel(PAVED_ROAD);
	set_property("no sticks",1);
	set_property("no teleport",1);
	set_property("no scry",1);
  	set_property("indoors",1);
  	set_property("light",2);
  	set_short("%^BOLD%^Lost Within The Void%^RESET%^");
  	set_long("%^BLUE%^You look along your body, amazed to see it "+
		"%^WHITE%^glowing faintly.%^BLUE%^  As far as you can tell "+
		"the only light in the area is somehow being generated from "+
		"your body.  The darkness around you closes in, battling the "+
		"small pocket of light you are somehow creating.  Pairs of "+
		"%^RED%^%^BOLD%^glowing red eyes%^RESET%^%^BLUE%^ hover in "+
		"the distance, glaring at you with an unwavering gaze.  The "+
		"eyes seem to float in all directions around you.  You become "+
		"disoriented watching the eyes, unsure as to whether you or "+
		"the eyes are spinning.\n");
  	set_listen("default","%^CYAN%^A deep growl rumbles softly in the distance.");
  	set_items(([
    		"eyes" : "%^RED%^Several sets of eyes hover a few dozen yards "+
			"away.  Dark pupils surrounded by a brightly glowing red iris.  "+
			"As you stare, the growling seems to become a bit louder.",
    		"light" : "You are not sure how or why, but your body is glowing "+
			"faintly.  Your light seems to stretch out and battle the darkness, "+
			"creating a small pocket in this void for you to move around in."
    	]));
}
void pick_critters() {
      switch(random(9)){
case 0..2:  set_monsters(({MON"shadow"}),({random(2)+1}));
break;
case 3..4:  set_monsters(({MON"smastiff"}),({random(3)+2}));
break;
case 5..6:  set_monsters(({MON"shadow",MON"smastiff"}),({1,1}));
break;
case 7..8: 
break;
      }
}
