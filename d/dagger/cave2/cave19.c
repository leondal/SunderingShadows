#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "southwest" : "/d/dagger/cave2/cave15",
      "north" : "/d/dagger/cave2/cave23",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
