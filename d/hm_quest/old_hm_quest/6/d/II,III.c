#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
	        "north" : MAZEDIR+"6/d/II,II",
		"south" : MAZEDIR+"6/d/II,IV",
		"east"  : MAZEDIR+"6/d/III,III",
                "west"  : MAZEDIR+"6/d/I,III"
           ]) );
}

