#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "south" : "/d/dagger/cave2/cave26",
      "northeast" : "/d/dagger/cave2/cave36",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
