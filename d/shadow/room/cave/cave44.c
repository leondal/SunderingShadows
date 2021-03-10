//cave44.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"west" : CAVEDIR+"cave43",
	"south" : CAVEDIR+"cave45"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblin"}),20,5);

}
*/