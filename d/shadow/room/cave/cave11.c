//cave11.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"north"     : CAVEDIR+"cave21",
	"south"     : CAVEDIR+"cave71",
	"west"      : CAVEDIR+"cave10",
	"east"      : CAVEDIR+"cave12"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat",MONDIR+"rat"}),20,3);
}
*/