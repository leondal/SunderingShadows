//cave28.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_smell("default","The pungent odor of ammonia fills your nostrils.");
    set_exits(([
	"south"      : CAVEDIR+"cave27",
	"north"      : CAVEDIR+"cave29"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantbat",MONDIR+"bat"}),40,5);
}
*/