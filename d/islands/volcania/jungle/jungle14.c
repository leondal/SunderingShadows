// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle14.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"southeast" : "jungle11",
	
	]));
}

