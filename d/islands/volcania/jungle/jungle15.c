// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle15.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"west" : "jungle14",
	
	]));
}

