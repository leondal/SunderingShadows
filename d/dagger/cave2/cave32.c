#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "south" : "/d/dagger/cave2/cave28",
      "north" : "/d/dagger/cave2/cave37",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
