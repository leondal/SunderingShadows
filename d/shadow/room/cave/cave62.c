//cave62.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_exits(([
        "north" : CAVEDIR+"cave61",
        "southeast" : CAVEDIR+"cave63"
    ]));
    set_pre_exit_functions(({"north", "southeast"}), ({"bomb_exits", "bomb_exits"}));
    set_property("collapse",1);
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"gnoll"}),20,5);

}
*/
