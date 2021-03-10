#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "south" : "/d/dagger/cave2/cave32",
      "north" : "/d/dagger/cave2/cave45",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
