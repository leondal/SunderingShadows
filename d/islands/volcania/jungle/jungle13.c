// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle13.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"east" : "jungle14",
	"south" : "jungle9",
	
	]));
}

