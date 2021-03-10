//updated to reflect move of Koenig.  Should be changed to a new dir.  Circe 11/29/03
#include <std.h>
#include <objects.h>
#include "kai.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Along a dusty road");
    set_long(
@KAYLA
The road here begins to move over the hills, leading a straight 
path to the cornfields.  Although they seem to have been desolate 
at one time, they have been tended to recently and some new growth 
is beginning to show.
KAYLA
    );
     set_smell("default","The earthy scent of the fields rises on the mountain air.");
     set_listen("default","You hear the gentle rustling of the wind.");
    set_exits(([
       "east" : "/d/koenig/fields/room/field3",
       "west" : "/d/koenig/village/dusty4"
    ] ));
}