//cave41.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"east"      : CAVEDIR+"cave31",
	"northwest" : CAVEDIR+"cave42",
	"southeast" : CAVEDIR+"cave10",
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),10,5);

}
*/