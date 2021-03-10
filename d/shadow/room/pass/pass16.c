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
%^WHITE%^The Crossroads
%^ORANGE%^All around you lie the Charu Mountains. They are very intimidating, looming high in the sky. The road winds through the mountains. There is a small road leading down into a large valley to the east. Path to the northeast leads to The Exchange.
MELNMARN
);
    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the
valleys.");


    set_items(([
        "road":"A new road through the mountains.",
        "mountains":"They are impressive, even from here.",
        ]));

    set_exits(([
        "south" : PASSDIR+"pass15",
        "east" : "/d/koenig/village/dusty1",
     "west":FORESTDIR+"owagon43",
        "north" : PASSDIR+"pass17",
       "northeast" : "/d/dagger/exchange/rooms/entrance"
        ]));
}
