//cave78.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
        "east" : CAVEDIR+"cave77",
        "southeast" : CAVEDIR+"cave79"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"orccaptain"}),20,5);

}
*/