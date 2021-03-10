#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : MAZEDIR+"2/a/III,II",
                "west"  : MAZEDIR+"2/a/II,III"
           ]) );
}

