//cave53.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_exits(([
	"northwest" : CAVEDIR+"cave52",
	"south" : CAVEDIR+"cave54",
	"southwest" : "/d/shadow/room/mountain/tunnel09",
    ]));
    set_pre_exit_functions(({"northwest", "south"}), ({"bomb_exits", "bomb_exits"}));
    set_property("collapse",1);
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"hobgoblin"}),10,5);
}
*/