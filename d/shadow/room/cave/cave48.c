//cave48.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits(([
	"north" : CAVEDIR+"cave47",
	"southeast" : CAVEDIR+"cave49"
    ]));
    set_pre_exit_functions(({"north", "southeast"}), ({"bomb_exits", "bomb_exits"}));
    set_property("collapse",1);
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblincaptain"}),30,5);

}
*/