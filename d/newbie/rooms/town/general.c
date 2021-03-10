#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_name("General Store");
	set_short("Odds and Ends");
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_long(
	"You are standing in the general store, which is southwest of the town square. There are all sorts of goods that adventurers might need hanging on the walls and tucked away on the shelves about the room. There is everything here from belt pouches and sacks to lockable chests and climbing tools. Most anything that you would need on a long journey can be found here, except for food and drink.\n\n  %^BOLD%^<help shop> will provide a list of shop commands"
	);
	set_property("light",2);
	set_smell("default","The store has a stale, dry quality to the air.");
	set_listen("default","You can hear people passing by on the streets outside.");
	set_items(([
	({"walls","shelves","equipment","goods"}) : "The various items that the store sells are hung on the walls and stocked on the shelves about the store. If you're wanting to look at something, the shop keeper will be more than happy to show it to you."
	]));
	set_exits(([
	"north" : MAINTOWN"wstreet1",
	"east" : MAINTOWN"sstreet1"
	]));
}

void init(){
   ::init();
   add_action("sell","sell");
}

void reset() {
   ::reset();
   if(!present("caeleb")) {
      find_object_or_load(MON"caeleb")->move(TO);
   }
}

int sell(string str){
   if(!str) return 0;
   if(str != "scroll") return 0;
   if(!present("caeleb")) return 0;
   tell_object(TO,"MAGENTA%^Caeleb says%^RESET%^:  Sorry, not dealing "+
      "in those things anymore.  I worked out a deal with Zabeth in the "+
      "wizard's tower.  She'll be takin' those from now on.");
   tell_object(TO,"Caeleb grins.");
   tell_object(TO,"%^MAGENTA%^Caeleb says%^RESET%^:  Gettin' a nice "+
      "cut too.");
   return 1;
}