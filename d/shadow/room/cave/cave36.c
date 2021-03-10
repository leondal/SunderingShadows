//cave36.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
   set_smell("default","The smell of sulfur fills your nostrils.");
    set_exits(([
	"west"  : CAVEDIR+"cave35",
	"northeast"  : CAVEDIR+"cave37"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"koboldcaptain",MONDIR+"kobold"}),40,5);
}
*/