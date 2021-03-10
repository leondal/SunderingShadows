// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle16.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"west" : "jungle15",
	"south" : "jungle12",
	
	]));
}

