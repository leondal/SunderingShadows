#include <std.h>
#include "../pass.h"
inherit ROOM;

void create(){
    ::create();
   set_travel(DIRT_ROAD);
   set_terrain(OLD_MOUNTS);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
%^CYAN%^All around you lie the Charu Mountains. They are very intimidating, looming high in the sky. The road winds through the mountains.
MELNMARN
);

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");


    set_items(([
	"road":"A new road through the mountains.",
	"mountains":"They are impressive, even from here.",
	]));

    set_exits(([
	"southeast" : PASSDIR+"pass26",
	"northeast" : PASSDIR+"pass28",
   	]));
}
