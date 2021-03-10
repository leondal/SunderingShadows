//cave72.c
#include "../cave.h"

inherit CAVEDIR+"inherit/cave.c";

void create(){
    ::create();
    set_exits(([
        "northwest" : CAVEDIR+"cave71",
        "southeast" : CAVEDIR+"cave73"
    ]));
    set_smell("default","The smell of rotted flesh fills your nostrils.");
    set_listen("default","You hear the sounds of water dripping.");
    set_pre_exit_functions( ({"northwest", "southeast"}), ({"bomb_exits", "bomb_exits"}) );
    set_property("collapse",1);
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"orc"}),20,2);

}
*/