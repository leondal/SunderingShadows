#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : MAZEDIR+"2/d/I,II",
                "south" : MAZEDIR+"2/d/I,IV",
                "east"  : MAZEDIR+"2/d/II,III"
           ]) );
}

