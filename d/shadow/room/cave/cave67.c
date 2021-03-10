//cave67.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
        "northeast" : CAVEDIR+"cave66",
        "west" : CAVEDIR+"cave68"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"gnoll",MONDIR+"gnollcaptain"}),30,5);

}
*/