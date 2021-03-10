//cave46.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"northwest" : CAVEDIR+"cave45",
	"east" : CAVEDIR+"cave47"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblin",MONDIR+"goblincaptain"}),30,5);

}
*/