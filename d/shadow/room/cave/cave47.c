//cave47.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west" : CAVEDIR+"cave46",
	"south" : CAVEDIR+"cave48"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblin",MONDIR+"goblincaptain"}),30,6);

}
*/