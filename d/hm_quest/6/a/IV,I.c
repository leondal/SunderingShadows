#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "west"  : MAZEDIR+"6/a/III,I"
           ]) );
}

