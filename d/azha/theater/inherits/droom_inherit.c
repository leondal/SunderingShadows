#include <std.h>
#include "../theater.h"
inherit CROOM;

	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
}