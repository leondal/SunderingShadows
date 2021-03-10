#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "west"  : MAZEDIR+"2/b/III,I"
           ]) );
}

