#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create() {
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(GARDEN);
	set_property("indoors",0);
	set_property("light",2);
	set_name("A front yard");
	set_short("A front yard");
	set_long(
	"You are standing in the front yard of someone's house. The lawn"+
	" is kept carefully manicured. The %^BOLD%^%^GREEN%^grass%^RESET%^"+
	" looks lush and healthy. There is a rose bush on either side of"+
	" the yard. Near the house are some carefully trimmed hedges. A"+
	" little worn dirt path leads from the street up to the house."
	);
	set_smell("default","You smell the sweet scent of roses.");
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
	" outside is painted %^GREEN%^dark green%^RESET%^ and it has a"+
	" %^BOLD%^white%^RESET%^ trim. You see a chimney on the east side of"+
   " the roof. A few steps lead up to the doorway.",
	"door" : "%^BOLD%^A pretty green door leads into the house.",
	({"rose bush","rose bushes","rosebush"}) : "On either side of the"+
	" yard is a rose bush. The one on the east has lovely %^BOLD%^%^RED%^red%^RESET%^"+
	" roses, while the one on the east has beautiful %^YELLOW%^yellow%^RESET%^"+
	" flowers. They both give off a sweet scent.",
	]));
	set_exits(([
	"south" : ROOMS+"street32",
	"north" : ROOMS+"house8",
	]));
	set_door("door",ROOMS+"house8","north","lliira house key");
   set_locked("door",1);
   lock_difficulty("door",-70,"lock");
	set_trap_functions( ({ "door" }),  ({ "lock_trap" }), ({ "pick" })	);
}

int lock_trap(){
   toggle_trap("door","pick","lock");
   new("/cmds/spells/h/_hideous_laughter")->use_spell(TO,TP,20,100,"mage");
   tell_object(TP,"%^BOLD%^Something flashes briefly from the lock!");
   tell_room(ETP,TPQCN+" seems suddenly distracted from trying to pick the "
    "lock.",TP);
	return 1;
}


void init() {
   ::init();
   add_action("whistle","whistle");
}

void whistle(string str) {
   if(str != "melody") return 0;
   if((string)TP->query_name() != "lliira" && (string)TP->query_name() != "singer" && !avatarp(TP)) return 0;
   find_object_or_load("/d/antioch/antioch2/rooms/house8");
   if(!query_locked("door")) {
      tell_object(TP,"You whistle a catchy melody and hear the door click as it locks.");
      tell_room(ETP,""+TPQCN+" whistles a catchy melody and you hear the"+
      " door click as it locks.",TP);
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/antioch/antioch2/rooms/house8"->set_locked("door",1);
      "/d/antioch/antioch2/rooms/house8"->set_open("door",0);
      return 1;
   }
   tell_object(TP,"You whistle a catchy melody and the door unlocks itself.");
   tell_room(ETP,""+TPQCN+" whistles a catchy melody.",TP);
   TO->set_locked("door",0);
   "/d/antioch/antioch2/rooms/house8"->set_locked("door",0);
   return 1;
}

