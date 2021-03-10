//cave10.c
#include "../cave.h"

inherit CAVERAT;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"east"      : CAVEDIR+"cave11",
	"northeast" : CAVEDIR+"cave21",
	"north"     : CAVEDIR+"cave31",
	"northwest" : CAVEDIR+"cave41",
	"west"      : CAVEDIR+"cave9",
	"southwest" : CAVEDIR+"cave51",
	"south"     : CAVEDIR+"cave61",
	"southeast" : CAVEDIR+"cave71",
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),20,2);

}
*/