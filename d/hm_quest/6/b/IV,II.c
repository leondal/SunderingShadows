#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : MAZEDIR+"6/b/IV,I",
                "west"  : MAZEDIR+"6/b/III,II"
           ]) );
}

