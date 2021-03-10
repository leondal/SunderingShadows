//cave57.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
	"northwest" : CAVEDIR+"cave56",
	"east" : CAVEDIR+"cave58"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"hobgoblin",MONDIR+"hobgoblincaptain"}),30,5);

}
*/