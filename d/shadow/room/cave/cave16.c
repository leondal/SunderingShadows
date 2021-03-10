//cave16.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"northeast"      : CAVEDIR+"cave15",
	"southwest"      : CAVEDIR+"cave17"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),10,6);
}
*/