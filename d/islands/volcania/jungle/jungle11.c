// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle11.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"northeast" : "jungle16",
	"south" : "jungle7",
	
	]));
}

