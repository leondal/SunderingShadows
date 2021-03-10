#include <std.h>
#include "../../newbie.h"
inherit VAULT;

void create()
{
	::create();
	set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_short("The Laughing Blade");
	set_long(
	"This is the weapons shop in the town of Offestry. It is kept continually"+
	" stocked with finely crafted weapons for the adventurers that are constantly"+
	" wondering through town. There are rows of weapons carefully arranged"+
	" in cases along the walls. The shop keeper stands behind the counter,"+
	" ready and waiting to assist you. He is willing to show you the items"+
	" if you desire to look at your purchase before making your final decision."+
	"\n\n%^BOLD%^<help shop> will provide a list of shop commands"

	);
	set_property("light",2);
	set_smell("default","The room is filled with the oils used to polish weapons.");
	set_listen("default","You can hear the people walking past on the streets outside.");
	set_items(([
	"counter" : "The shop keeper is standing behind a large counter that is"+
	" kept nicely polished. Here he will gladly show you any weapons that you"+
	" may be interested in.",
	({"wall","walls","cases","weapons"}) : "The walls of the shop are covered"+
	" in glass cases with weapons carefully placed inside them. If you wish"+
	" to see one, the shop keeper can show it to you.",
	]));
	set_exits(([
	"south" : MAINTOWN"wstreet2",
	//"east" : MAINTOWN"nstreet1",
	]));
}

void reset()
{
   ::reset();
   if(!present("daven")) {
      find_object_or_load(MON"daven")->move(TO);
   }
}
