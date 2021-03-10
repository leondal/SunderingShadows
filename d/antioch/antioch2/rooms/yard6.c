//changed to reflect change in owners.  Zeal bought it 
//from Gwenhwyfar.  Circe 5/2/04
#include <std.h>
#include "../antioch.h"
inherit VAULT;
#define OWNERS ({"amberly","selve","zeal"})

void create() {
	::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A front yard");
	set_long(
	"You are standing in the front yard of someone's house. The lawn"+
	" is kept carefully manicured. The %^BOLD%^%^GREEN%^grass%^RESET%^"+
	" looks lush and healthy. A row of %^MAGENTA%^pansies%^RESET%^"+
	" are planted at the front of the yard. Near the house are some"+
	" carefully trimmed hedges. A little worn dirt path leads"+
	" from the street up to the house."
	);
	set_smell("default","You smell the fresh mountain air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"lawn" : "The lawn is kept carefully manicured.",
	"grass" : "%^BOLD%^%^GREEN%^The grass is a pretty green shade,"+
	" it looks lush and vibrant.",
	"hedges" : "%^GREEN%^Near the front of the house some hedges are"+
	" kept neatly trimmed.",
	({"path","dirt path"}) : "A little worn dirt path leads from the"+
	" street up to the house.",
	"house" : "The house is an elegant two story structure. The"+
	" outside is painted %^BOLD%^%^CYAN%^blue%^RESET%^ and it has a"+
	" %^BOLD%^%^BLUE%^navy%^RESET%^ trim. A few steps lead up to"+
	" the front porch and the doorway.",
	"door" : "%^BOLD%^A pretty blue door leads into the house.",
	({"pansies","row of pansies"}) : "%^MAGENTA%^Near the front of the"+
	" yard is a very straight row of pansies. Most of them are a deep"+
	" purple shade, but there are a few %^BLUE%^dark blue%^MAGENTA%^"+
	" pansies mixed in.",
	]));
	set_exits(([
	"north" : ROOMS+"street31",
	"south" : ROOMS+"house6",
	]));
   set_door("door",ROOMS+"house6","south","zeal house key");
   set_locked("door",1);
}

void init()
{
   ::init();
   add_action("recite","recite");
}

void recite(string str)
{
   if(str != "poem") return 0;
   if((member_array((string)TP->query_name(),OWNERS)== -1) && (!avatarp(TP))) return 0;
   find_object_or_load("/d/antioch/antioch2/rooms/house6");
   if(!query_locked("door")) {
      tell_object(TP,"You recite a poem and hear a faint click as the door locks.");
      tell_room(ETP,""+TPQCN+" recites a poem and you hear a faint click as the door locks itself.",TP);
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/antioch/antioch2/rooms/house6"->set_locked("door",1);
      "/d/antioch/antioch2/rooms/house6"->set_open("door",0);
      return 1;
   }
   tell_object(TP,"You recite a poem and hear a click as the door unlocks itself.");
   tell_room(ETP,""+TPQCN+" recites a poem.",TP);
   TO->set_locked("door",0);
   "/d/antioch/antioch2/rooms/house6"->set_locked("door",0);
   return 1;
}
