#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "northwest" : "/d/dagger/cave2/cave29",
      "north" : "/d/dagger/cave2/cave30",
      "southeast" : "/d/dagger/cave2/cave25",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
