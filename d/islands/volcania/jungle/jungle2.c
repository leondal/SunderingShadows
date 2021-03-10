// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle2.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"north" : "jungle6",
	"east" : "jungle3",
	
	]));
}

