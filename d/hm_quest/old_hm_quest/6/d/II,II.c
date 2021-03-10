#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
	        "south" : MAZEDIR+"6/d/II,III",
                "west" : MAZEDIR+"6/d/I,II"
           ]) );
}

