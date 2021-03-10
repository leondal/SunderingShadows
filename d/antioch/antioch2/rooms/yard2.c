#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A front yard");
	set_long(
	"You are standing in the front yard of someone's house. The lawn"+
	" is kept carefully manicured. The %^BOLD%^%^GREEN%^grass%^RESET%^"+
	" looks lush and healthy. A row of pretty %^YELLOW%^daisies%^RESET%^"+
	" are planted at the front of the yard. Near the house are some"+
	" carefully trimmed hedges. A little worn dirt path leads from the"+
	" street up to the house."
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
	"house" : "The house is pretty, one story in height. The"+
	" outside is painted %^BOLD%^white%^RESET%^ and it has a"+
	" %^BOLD%^%^CYAN%^sky blue%^RESET%^ trim. A few steps lead up to"+
	" the doorway.",
	"door" : "%^BOLD%^A pretty white door leads into the house.",
	({"daisies","row of daisies"}) : "%^YELLOW%^A row of pretty daises"+
	" are lined up at the front of the yard. They look well cared for"+
	" and are all in a perfect line.",
	]));
	set_exits(([
	"north" : ROOMS+"street29",
	"south" : ROOMS+"house2",
	]));
	set_door("door",ROOMS+"house2","south","antioch house key");
   set_locked("door",1);
}

void init()
{
   ::init();
   add_action("snap","snap");
}

void snap(string str)
{
   if(str != "fingers") return 1;
   if((string)TP->query_name() != "korath" && (string)TP->query_name() != "tansy" && !avatarp(TP)) return 1;
   find_object_or_load("/d/antioch/antioch2/rooms/house2");
   if(!query_locked("door")) {
      tell_object(TP,"You snap your fingers and hear a faint click as the door locks.");
      tell_room(ETP,""+TPQCN+" snaps "+TP->query_possessive()+" fingers together and you hear a faint click as the door locks itself.",TP);
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/antioch/antioch2/rooms/house2"->set_locked("door",1);
      "/d/antioch/antioch2/rooms/house2"->set_open("door",0);
      return 1;
   }
   tell_object(TP,"You snap your fingers and hear a gentle click as the door unlocks itself.");
      tell_room(ETP,""+TPQCN+" snaps "+TP->query_possessive()+" fingers.",TP);
   TO->set_locked("door",0);
   "/d/antioch/antioch2/rooms/house2"->set_locked("door",0);
   return 1;
}
