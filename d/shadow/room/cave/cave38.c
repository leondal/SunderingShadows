//cave38.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_smell("default","The smell of sulfur fills your nostrils.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"south"  : CAVEDIR+"cave37",
	"north"  : CAVEDIR+"cave39"
    ]));
    set_pre_exit_functions( ({"south", "north"}), ({"bomb_exits", "bomb_exits"}) );
    set_property("collapse",1);
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"koboldcaptain",MONDIR+"kobold"}),30,5);
}
*/