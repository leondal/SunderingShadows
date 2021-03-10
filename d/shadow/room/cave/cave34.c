//cave34.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_smell("default","The smell of sulfur fills your nostrils");
    set_exits(([
	"southeast"  : CAVEDIR+"cave33",
	"north"  : CAVEDIR+"cave35"
    ]));
    set_pre_exit_functions(({"southeast", "north"}), ({"bomb_exits", "bomb_exits"}));
    set_property("collapse",1);
  
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"kobold"}),20,5);
}
*/