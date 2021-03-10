#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(1);
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_exits( ([
      "west" : "/d/dagger/cave2/cave10",
      "southeast" : "/d/dagger/cave2/cave12",
    ]) );
}

void init() {
    ::init();
}

void reset(){
    ::reset();

}
