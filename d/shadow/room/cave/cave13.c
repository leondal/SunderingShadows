//cave13.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"north"      : CAVEDIR+"cave12",
	"southeast"      : CAVEDIR+"cave14"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),20,5);
}
*/