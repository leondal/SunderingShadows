//cave27.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_smell("default","The pungent odor of ammonia fills your nostrils.");
    set_exits(([
	"east"       : CAVEDIR+"cave26",
	"north"      : CAVEDIR+"cave28"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantbat",MONDIR+"bat"}),20,5);
}
*/