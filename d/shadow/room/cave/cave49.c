//cave49.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"northwest" : CAVEDIR+"cave48",
	"down" : CAVEDIR+"cavern5"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblincaptain"}),40,5);

}
*/