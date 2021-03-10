//cave52.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
	"northeast" : CAVEDIR+"cave51",
	"southeast" : CAVEDIR+"cave53"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping."); 
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"hobgoblin"}),30,3);

}
*/