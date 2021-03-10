//cave18.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west"      : CAVEDIR+"cave17",
	"east"      : CAVEDIR+"cave19"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),20,3);
}
*/