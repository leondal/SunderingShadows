#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(1);
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_exits( ([
	"northwest" : "/d/dagger/cave2/cave11",
	"south" : "/d/dagger/cave2/cave13",
      ]));
}

void init() {
    ::init();
}

void reset() {
    ::reset();
}
