#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats and dripping water.");
    set_exits(([
	"west" : CAVEDIR+"cave8",
	"east" : CAVEDIR+"cave10"
    ]));
    set_pre_exit_functions( ({"west", "east"}), ({"bomb_exits", "bomb_exits"}) );
    set_property("collapse",1);
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),10,5);

}
*/