#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
	        "west"  : MAZEDIR+"4/c/III,I"
           ]) );
}
