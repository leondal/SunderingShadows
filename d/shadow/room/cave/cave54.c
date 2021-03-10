//cave54.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
	"north" : CAVEDIR+"cave53",
	"east" : CAVEDIR+"cave55",
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"hobgoblin"}),30,5);
}
*/