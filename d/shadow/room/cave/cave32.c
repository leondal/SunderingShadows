//cave32.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_smell("default","The smell of sulfur fills your nostrils.");
    set_exits(([
	"south"  : CAVEDIR+"cave31",
	"north"  : CAVEDIR+"cave33"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"kobold"}),20,5);
}
*/