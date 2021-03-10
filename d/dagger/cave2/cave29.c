#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "southeast" : "/d/dagger/cave2/cave26",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
