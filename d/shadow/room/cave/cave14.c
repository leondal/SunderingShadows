//cave14.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"northwest"      : CAVEDIR+"cave13",
	"east"      : CAVEDIR+"cave15"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),40,2);
}
*/