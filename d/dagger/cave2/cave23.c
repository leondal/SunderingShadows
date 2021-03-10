#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "west" : "/d/dagger/cave2/cave22",
      "south" : "/d/dagger/cave2/cave19",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
