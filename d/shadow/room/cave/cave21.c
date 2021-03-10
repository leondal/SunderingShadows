//cave21.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west"      : CAVEDIR+"cave31",
	"south"     : CAVEDIR+"cave11",
	"northeast" : CAVEDIR+"cave22",
	"southwest" : CAVEDIR+"cave10"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),30,5);

}
*/