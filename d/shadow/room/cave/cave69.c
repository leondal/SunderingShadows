//cave69.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_exits(([
        "north" : CAVEDIR+"cave68",
        "down" : CAVEDIR+"cavern7"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
    set_pre_exit_functions( ({"north", "down"}), ({"bomb_exits", "bomb_exits"}) );
    set_property("collapse",1);
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"gnoll",MONDIR+"gnollcaptain"}),20,7);
}
*/