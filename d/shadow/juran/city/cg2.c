#include <std.h>
#include "../juran.h"

inherit VAULT;

int uses;

void create(){
    	::create();
    	set_name("Dark Clerics guild");
    	set_short("Dark Clerics guild");
    	set_long(
		"You have stepped into a bloody altar room.  The massive "+
		"stone altar dominates the room.  The altar is made from "+
		"obsidian and looks wet.  There are a couple small bowls "+
		"of holy water resting on tiny pillars on each side of the altar."
    	);
    	set_property("indoors",1);
    	set_property("light",-2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_listen("default","You can hear the faint prayers of other priests.");
    	set_smell("default","The smell of brimstone and blood fills the room.");
    	set_exits( ([
		"northwest" : JROOMS+"cg1",
    	]) );
    	set_items( ([
		({"pillar","water","holy water","bowl"}):"This holy water is "+
			"for use by clerics in their fight to gain power and serve "+
			"their lords.  To get a vial of it type <take water>.",
    	]) );
    	uses = 6;
}
void init(){
    	::init();
    	add_action("take","take");
}
void take(string str){
    	if(!str) return 0;
    	if(str != "water") return 0;
    	if(uses < 1) return notify_fail("There is no holy water left!\n");
    	tell_object(TP,"You take a vial of holy water from the bowl.");
    	tell_room(TO,TPQCN+" takes a vial of holy water from the bowl.",TP);
    	new("/d/shadow/room/city/cguild/paladin/hlywater")->move(TP);
    	uses -= 1;
    	return 1;
}
void reset(){
    	::reset();
    	tell_room(TO,"An altar boy runs into the room and refills the holy water.");
    	uses = 6;
    	return 1;
}
