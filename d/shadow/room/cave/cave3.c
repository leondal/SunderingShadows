//cave3.c
#include "../cave.h"

inherit CAVERAT;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west" : CAVEDIR+"cave4",
	"east" : CAVEDIR+"cave2"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),20,5);

}
*/