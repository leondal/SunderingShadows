#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "south" : MAZEDIR+"6/c/I,IV",
                "east"  : MAZEDIR+"6/c/II,III"
           ]) );
}

