// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle6.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"west" : "jungle5",
	
	]));
}

