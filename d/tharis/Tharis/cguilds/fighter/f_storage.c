#include <std.h>

inherit ROOM;

void create(){
	::create();
   set_property("no teleport",1);
	
	set_properties((["light":2,"indoors":1]));
	
	set("short","thief storage");
	set("long","If your here you shouldn't be");
}

void reset(){
	::reset();
	
	
	
	}
