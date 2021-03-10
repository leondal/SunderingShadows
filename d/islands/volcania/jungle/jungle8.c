// A Jungle Room in Volcania
// Thorn@ShadowGate
// jungle8.c


#include "/d/islands/volcania/volcania.h"

inherit JUNGLE_ROOM;

create() {
	::create();
	set_exits(([
	"northwest" : "jungle11",
	"south" : "jungle4",
	
	]));
}

