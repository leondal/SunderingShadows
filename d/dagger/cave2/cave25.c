#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "south" : "/d/dagger/cave2/cave22",
      "northwest" : "/d/dagger/cave2/cave26",
      "north" : "/d/dagger/cave2/cave27",
      "northeast" : "/d/dagger/cave2/cave28",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
