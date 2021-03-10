//cave43.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"southeast" : CAVEDIR+"cave42",
	"east" : CAVEDIR+"cave44"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblin"}),30,5);

}
*/