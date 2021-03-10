// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle12.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"east" : VCAN+"jungle",
	"west" : "jungle11",
	
	]));
}

