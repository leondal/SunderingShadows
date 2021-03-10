#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(1);
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_exits( ([
      "southeast" : "/d/dagger/cave2/cave8",
      "north" : "/d/dagger/cave2/cave10",
    ]) );
}

void init() {
    ::init();
}

void reset(){
    ::reset();

}
