#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : "/d/hm_quest/enterence",
                "south" : MAZEDIR+"2/a/I,II",
           ]) );
}

