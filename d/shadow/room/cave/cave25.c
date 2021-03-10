//cave25.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_smell("default","The pungent odor of ammonia fills your nostrils.");
    set_exits(([
	"southwest"  : CAVEDIR+"cave24",
	"north"      : CAVEDIR+"cave26"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantbat"}),40,5);
}
*/