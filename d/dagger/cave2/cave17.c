#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "west" : "/d/dagger/cave2/cave16",
      "south" : "/d/dagger/cave2/cave14",
      "east" : "/d/dagger/cave2/cave18",
      "north" : "/d/dagger/cave2/cave21",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
