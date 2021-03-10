//cave79.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_exits(([
        "northwest" : CAVEDIR+"cave78",
        "down" : CAVEDIR+"cavern8"
    ]));
    set_pre_exit_functions(({"northwest", "down"}), ({"bomb_exits", "bomb_exits"}));
    set_property("collapse",1);
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"orc",MONDIR+"orccaptain"}),10,6);

}
*/