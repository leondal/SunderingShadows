#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "east"  : MAZEDIR+"2/a/III,IV",
                "west"  : MAZEDIR+"2/a/I,IV"
           ]) );
}

