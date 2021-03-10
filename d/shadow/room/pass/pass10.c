#include <std.h>
#include "../pass.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
All around you lie the Charu Mountains. They are very intimidating, looming high in the sky. The road winds through the mountains. There is a small opening in the side of the mountain.
MELNMARN
);

    set_smell("default","You catch a whiff of something foul from nearby.");
    set_listen("default","You can hear the wind blowing through the valleys.");
    set_items(([
	"road":"A new road through the mountains.",
  "mountains":"they are impressive, even from here.",
	"opening":"You see a hole, maybe if you tried to enter?"
	]));

    set_exits(([
	"south" : PASSDIR+"pass9",
        "enter" : CAVEDIR+"cave1",
	"north" : PASSDIR+"pass11",
   	]));
    add_invis_exit("enter");
    add_pre_exit_function( "north", "whiff" );
}

int whiff() {
    if(TP->query_level() < 15 && !random(20))
        tell_object(ETO,"You catch a whiff of stale, foul air from somewhere "
           "just as you move north.\n");
    return 1;
}
