//cave68.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
        "south" : CAVEDIR+"cave69",
        "east" : CAVEDIR+"cave67"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"gnollcaptain"}),30,6);

}
*/