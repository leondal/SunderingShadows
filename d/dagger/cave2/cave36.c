#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
      "southwest" : "/d/dagger/cave2/cave30",
      "west" : "/d/dagger/cave2/cave35",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
