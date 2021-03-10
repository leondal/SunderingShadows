//cave61.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west"      : CAVEDIR+"cave51",
	"east"      : CAVEDIR+"cave71",
	"north"     : CAVEDIR+"cave10",
	"south"     : CAVEDIR+"cave62"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),20,2);

}
*/