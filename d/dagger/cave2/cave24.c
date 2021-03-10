#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "southwest" : "/d/dagger/cave2/cave20",
      "south" : "/d/dagger/cave2/cave21",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
