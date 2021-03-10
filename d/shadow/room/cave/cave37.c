//cave37.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
   set_smell("default","The smell of sulfur fills your nostrils.");
    set_exits(([
	"southwest"  : CAVEDIR+"cave36",
	"north"  : CAVEDIR+"cave38"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"koboldcaptain"}),30,5);
}
*/