#include <std.h>
#include <daemons.h>
inherit ROOM;

string *registered;

void create(){
	::create();
      set_terrain(WOOD_BUILDING);
      set_travel(DIRT_ROAD);
	set_property("light", 2);
      set_property("indoors",1);
   //set_property("no teleport",1);
        set_short("The Torm thieves' guild shop");
	set_long("%^RESET%^%^ORANGE%^Dividing this room in half is the counter on which you find yourself on one side of.   On the other side stands the shopkeeper and behind him, his wares.  The room itself is simple and functional, no extravagance.%^RESET%^\n");
	set_exits(([
		"out":"/d/dagger/Torm/city/thieves/vethor_guild"
	]));
	set_smell("default","You smell whiffs of ammonia.");
	set_listen("default","You hear the shopkeeper drumming his fingers on the counter.");
	if(!present("feyd")) new("/d/retired/feyd")->move(TO);
}

void remove_member(string str){
	registered = SAVE_D->query_array("vethor_members");
	if(member_array(str, registered) != -1){
		SAVE_D->remove_name_from_array("vethor_members", str);
	}
}
