//cave26.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_smell("default","The pungent odor of ammonia fills your nostrils.");
    set_exits(([
	"west"     : CAVEDIR+"cave27",
	"south"    : CAVEDIR+"cave25"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantbat"}),30,5);
}
*/