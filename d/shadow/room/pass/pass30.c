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
All around you lie the Charu Mountains. They are very intimidating, looming high in the sky. The road winds through the mountains.

%^BOLD%^A %^ORANGE%^hole %^RESET%^%^BOLD%^descends down into darkness here.%^RESET%^
MELNMARN
);

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");


    set_items(([
	"road":"A new road through the mountains.",
	"mountains":"They are impressive, even from here.",
    "hole" : "%^BOLD%^%^BLACK%^This hole leads down into "+
    "darkness here. You could descend into it, if you were "+
    "brave or perhaps foolish, enough."
	]));

    set_exits(([
	"south" : PASSDIR+"pass29",
        "north" : "/d/antioch/wild/mount/pass_1"
   	]));

    set_climb_exits((["descend" : ({"/d/charucavern/wormlair/rooms/wormnar1_1", 20, 10, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");

}
