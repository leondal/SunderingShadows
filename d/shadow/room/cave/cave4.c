//cave4.c
#include "../cave.h"

inherit CAVERAT;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"southwest" : CAVEDIR+"cave5",
	"east" : CAVEDIR+"cave3"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),20,7);

}
*/