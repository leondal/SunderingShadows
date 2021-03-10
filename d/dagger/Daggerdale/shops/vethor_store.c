// store for Daggerdale thieves' guild

#include <std.h>
#include <daemons.h>

inherit ROOM;

string *registered;

void create(){
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
        set_property("no teleport",1);
	set_properties((["light":2,"indoors":1]));
	set("short","The Daggerdale thieves' guild shop");
	set("long",
@STYX
Dividing this room in half is the counter on which you find yourself on
one side of.   On the other side stands the shopkeeper and behind him,
his wares.  The room itself is simple and functional, no extravagance.
STYX
	);
	set_exits(([
		"out":"/d/dagger/Daggerdale/shops/vethor_guild"
	]));
	set_smell("default","You smell whiffs of ammonia.");
	set_listen("default","You hear the shopkeeper drumming his fingers on the counter.");
	set_items( ([
	]) );
}

void reset(){
	::reset();
	if(!present("nicoli"))
		new("/d/dagger/Daggerdale/shops/npcs/nicoli")->move(TO);
}

void init(){
    ::init();
}

void remove_member(string str){
	registered = SAVE_D->query_array("vethor_members");
	if(member_array(str, registered) != -1){
		SAVE_D->remove_name_from_array("vethor_members", str);
	}
}
