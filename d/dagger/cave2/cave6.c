#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(1);
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_exits( ([
	"northeast" : "/d/dagger/cave2/cave5",
	"west" : "/d/dagger/cave2/cave7",
      ]));
}

void init() {
    ::init();
}

void reset(){
    ::reset();
}
