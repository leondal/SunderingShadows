#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "southwest" : "/d/dagger/cave2/cave25",
      "north" : "/d/dagger/cave2/cave32",
      "northeast" : "/d/dagger/cave2/cave33",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
