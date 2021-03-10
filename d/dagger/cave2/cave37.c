#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "north" : "/d/dagger/cave2/cave42",
      "south" : "/d/dagger/cave2/cave32",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
