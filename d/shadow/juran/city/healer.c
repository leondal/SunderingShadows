#include <std.h>
#include "../juran.h"

inherit HEALER;

void create() {
    	::create();
    	set_light(2);
    	set_property("training",1);
    	set_indoors(1);
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_short("Snukclam's ointments");
    	set_long(
   "Snukclam's place is filled with the strong aroma of herbal medicines "+
    		"and body odor. Two pallets of straw are on the floor and the floor "+
   "is none too clean. The room is filled with the moans and the wails of "+
   "pain of the sick and wounded from the past and the present.");
    	set_smell("default", "The strong odor of herbal medicines assults your nose.");
    	set_listen("default", "You hear moans and groans from the wounded people.");
    	set_exits( ([
        	"north" : JROOMS+"r27",
        	"southeast" : JROOMS+"cg1"
    	] ));
    	set_name("Snukclam");
//    	set_pre_exit_functions( ({"southeast"}), ({"GoThroughDoor"}) );
}

/*
int GoThroughDoor(){
    	if(TP->is_class("cleric") || avatarp(TP)) return 1;
    	tell_object(TP, "You are not allowed in there oh ye of little faith.");
    	return 0;
}
*/

void reset(){
    ::reset();
    if(!present("snukclam")) new(JMONS+"snukclam")->move(TO);
}
