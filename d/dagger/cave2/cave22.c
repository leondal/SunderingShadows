#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "west" : "/d/dagger/cave2/cave21",
      "south" : "/d/dagger/cave2/cave18",
      "east" : "/d/dagger/cave2/cave23",
      "north" : "/d/dagger/cave2/cave25",
      "up" : "/d/dagger/cave2/cave13",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
