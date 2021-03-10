//cave42.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"northwest" : CAVEDIR+"cave43",
	"southeast" : CAVEDIR+"cave41"
    ]));
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblin"}),20,5);

}
*/