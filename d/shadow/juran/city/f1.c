//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit VAULT;

void create(){
 	object ob;
   	::create();
	set_name("corrupted fountain");
	set_short("corrupted fountain");
	set_long(
    		"%^RESET%^%^CYAN%^"+
		"A fountain sits in the center of the park here.  Crusty brown "+
		"water still flows from the top of the fountain staining the "+
                "stones as it trickles down into the large circular basin.  "+
		"Algae grows from many places on the stone of the fountain "+
		"and the water that is pooled in the basin looks fetid and "+
                "thick.  The top of the fountain was once a statue of a beautiful "+
		"woman, but most of that has long since erroded away.  Now all "+
		"that can be seen is the corroded statue of the woman, the "+
		"tainted water flowing out from the crook of her arm, but her "+
		"face is eerily untouched by the ravages of time and neglect.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",0);
	set_property("light",-2);
    	set_terrain(CITY);
    	set_travel(PAVED_ROAD);
	set_smell("default","The smell of fetid water fills the air.");
	set_listen("default","It is as quiet as death except for a gurgling "+
		"you can hear coming from the fountain.");
	set_items(([
      	"fountain" : "Although the fountain has not been taken care of "+
      		"for a long time water, or what passes for water, continues "+
      		"to trickle out of the statue at the top of the fountain.  "+
      		"The thick brown water pools in the bottom of the fountain "+
      		"and gives off an unhealthy aroma.\n",
		"statue" : "The statue of what was once a lovely woman stands "+
                        "atop the fountain.  She stands casually and there once was "+
			"probably an urn carried in her arms, but the urn has long "+
			"since corroded away.  The fetid brown water pours out from "+
			"the crook of the statues elbow.  The statue is very corroded "+
			"except for the face, the face looks to be untouched by the "+
			"ravages of time.\n",
		({"vines","vine","thorns","thorn"}) : "Wicked thorns poke out "+
			"menacingly from the vines that cover the tree trunks and ground.\n"
        	]));
    	set_exits(([
   		"northwest" : JROOMS+"p8",
   		"north" : JROOMS+"p1",
   		"northeast" : JROOMS+"p2",
   		"east" : JROOMS+"p3",
   		"southeast" : JROOMS+"p4",
   		"south" : JROOMS+"p5",
   		"southwest" : JROOMS+"p6",
   		"west" : JROOMS+"p7"
    	]));
/*

  	ob = new("std/bboard");
  	ob->set_name("board");
  	ob->set_id( ({ "board", "bulletin board", "reality board" }) );
  	ob->set_board_id("main_board");
  	ob->set("short", "The Juran Reality Board");
  	ob->set("long", "An old corroded board where the adventurers "
          "who pass through the ruins of Juran post information on the "
          "reality they have discovered.\n");
  	ob->set_max_posts(50);
  	ob->set_location("/d/shadow/juran/city/f1");
*/

   find_object_or_load("/d/npc/ookla");
   find_object_or_load("/d/npc/skinkpuss");
   find_object_or_load("/d/npc/grumblecuss");
   find_object_or_load("/d/npc/teles");
}

