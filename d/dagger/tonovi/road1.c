#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road to Tonovi");
    set_long(
      "You are on the northwest streatch of the road between Tonovi and the crossroads on the plains.  You are walking in a valley between two hills, one to the northeast and one to the southwest.  To the northwest you can see the high towers of Tonovi around the gate off in the distance."
    );
    set_smell("default", "The smell of wildflowers floats to you on a cool breeze.");
    set_listen("default", "You hear a hawk cry out in the distance.");

    set_items( ([
	"valley" : "This valley is formed between two of the great green hills on the plains.",
	"towers" : "These towers hold the archers that watch the road as it approaches the gate to the town.",
	"gate" : "From here the huge gate looks tiny.",
      ]) );

    set_exits( ([
	"southeast" : RPATH "crossrd",
	"northwest" : RPATH "road2",
      ]) );

}

