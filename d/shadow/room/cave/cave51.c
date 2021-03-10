//cave51.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"east"      : CAVEDIR+"cave61",
	"northeast" : CAVEDIR+"cave10",
	"southwest" : CAVEDIR+"cave52"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),20,3);

}
*/