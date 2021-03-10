//cave8.c
#include "../cave.h"

inherit CAVERAT;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats and dripping water.");
    set_exits(([
	"west" : CAVEDIR+"cave7",
	"east" : CAVEDIR+"cave9"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),80,5);

}
*/