#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "south" : MAZEDIR+"2/c/II,IV",
                "west"  : MAZEDIR+"2/c/I,III"
           ]) );
}

