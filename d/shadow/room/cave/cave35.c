//cave35.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
   set_smell("default","The smell of sulfur fills your nostrils.");
    set_exits(([
	"south"  : CAVEDIR+"cave34",
	"east"  : CAVEDIR+"cave36"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"koboldcaptain",MONDIR+"kobold"}),30,5);
}
*/