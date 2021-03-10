//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit ROOM;

void create(){
	::create();
	set_name("tunnel");
   set_short("tunnel");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"You are in a tunnel leading east and west."+
   	" The tunnel itself looks to be of "+
   	"recent construction and is made very well.  The walls, "+
   	"ceiling, and floor are made of native stone cut, "+
   	"and mortared, to fit perfectly.  The stonework is "+
   	"of such high quality it can only be of dwarven construction.  "+
   	"There are no sconces, or other devices, to hold torches, or "+
   	"lanterns.  Chisel marks can be seen in various places and "+
   	"look deliberate."+
   	"%^RESET%^"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","Dust tickles your nose making you almost sneeze.");
   set_listen("default","You can hear muffled unidentified noises.");
   set_items(([
   	({"floor","walls","wall","ceiling"}) : "The entire tunnel "+
   		"is made of native stone that has been cut, and mortared, "+
   		"to fit together perfectly.  The construction has made the "+
   		"tunnel extremely stable and is of very high quality.  "+
   		"Chisel marks have been deliberately placed on the walls "+
   		"near the floor at regular intervals.",
   	({"chisel marks", "chisel mark", "marks", "mark"}) : "The marks "+
   		"are not easily seen and are no doubt a code placed by the "+
   		"builders for a purpose that only they can say.  Knowing "+
   		"dwarves it is probably the amount of minutes since their "+
   		"last ale.  This section of wall has fourteen marks.",
   	"stones" : "The stones here are much the same as the rest "+
   		"of the tunnel except for the interesting shapes of three "+
   		"of them on the west wall."
  	]));
   set_exits(([
   	"east" : STEFANO+"tunnel16",
   	"west" : STEFANO+"tunnel18"
	]));
}