//cave15.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west"      : CAVEDIR+"cave14",
	"southwest"      : CAVEDIR+"cave16"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),20,2);
}
*/