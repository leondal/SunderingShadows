//cave58.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_exits(([
	"west" : CAVEDIR+"cave57",
	"south" : CAVEDIR+"cave59"
    ]));
    set_property("collapse",1);
    set_pre_exit_functions( ({"west", "south"}), ({"bomb_exits", "bomb_exits"}) );
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"hobgoblincaptain"}),20,7);
}
*/