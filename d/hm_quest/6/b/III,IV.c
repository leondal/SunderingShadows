#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : MAZEDIR+"6/b/III,III",
	        "east"  : MAZEDIR+"6/b/IV,IV"
           ]) );
}
