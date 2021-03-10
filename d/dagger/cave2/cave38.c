#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "south" : "/d/dagger/cave2/cave33",
      "north" : "/d/dagger/cave2/cave43",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
