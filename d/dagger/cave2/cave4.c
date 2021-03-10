#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(1);
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_exits( ([
	"southwest" : RPATH "cave3",
	"north" : RPATH "cave5",
      ]));
}

void init() {
    ::init();
}

void reset(){
    ::reset();
}
