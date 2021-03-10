// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle5.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"north" : "jungle9",
	
	]));
}

