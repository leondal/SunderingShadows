#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_exits( ([
	"north" : "/d/dagger/cave2/cave17",
	"east" : "/d/dagger/cave2/cave15",
      ]));
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
