//cave71.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
    set_exits(([
	"west"      : CAVEDIR+"cave61",
	"north"     : CAVEDIR+"cave11",
	"northwest" : CAVEDIR+"cave10",
	"southeast" : CAVEDIR+"cave72",
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),10,5);

}
*/