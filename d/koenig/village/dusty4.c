//updated to reflect move of Koenig.  Should be changed to a new dir.  Circe 11/29/03
#include <std.h>
#include <objects.h>
#include "kai.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(FOOT_PATH);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Along a dusty road");
    set_long(
@KAYLA
You are travelling on a dusty road, from Dragon Pass Road to 
the west, to a large patch of fields in the rolling hills to the east.
The fields look run down, but they seem to be sprouting new growth as 
if they have only recently been tended.
KAYLA
    );
     set_smell("default","The earthy scent of the fields rises on the mountain air.");
     set_listen("default","You hear the gentle rustling of the wind.");
    set_exits(([
      "west" : "/d/koenig/village/dusty3",
       "east" : "/d/koenig/village/dusty5"
    ] ));
    set_items(([
       "road" : "It is a long, dusty road."
    ] ));
}