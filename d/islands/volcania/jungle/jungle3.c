// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle3.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"north" : "jungle7",
	
	]));
}

