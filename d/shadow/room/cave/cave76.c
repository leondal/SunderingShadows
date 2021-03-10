//cave76.c
#include "../cave.h"

inherit DDCAVE;

void create(){
    ::create();
    set_exits(([
        "northwest" : CAVEDIR+"cave75",
        "south" : CAVEDIR+"cave77"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"orc",MONDIR+"orccaptain"}),10,5);

}
*/