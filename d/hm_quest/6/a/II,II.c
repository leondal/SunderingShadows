#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : MAZEDIR+"6/a/II,I",
                "south" : MAZEDIR+"6/a/II,III"
           ]) );
}

