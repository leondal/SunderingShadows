#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
	        "east"  : MAZEDIR+"6/d/III,I",
                "west"  : MAZEDIR+"6/d/I,I"
           ]) );
}

