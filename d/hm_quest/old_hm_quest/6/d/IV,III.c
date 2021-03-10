#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
	        "north" : MAZEDIR+"6/d/IV,II",
		"south" : MAZEDIR+"6/d/IV,IV",
                "west"  : MAZEDIR+"6/d/III,III"
           ]) );
}
