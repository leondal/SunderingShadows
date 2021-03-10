#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : MAZEDIR+"6/a/II,II",
                "west"  : MAZEDIR+"6/a/I,III"
           ]) );
}

