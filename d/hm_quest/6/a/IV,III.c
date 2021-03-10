#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : MAZEDIR+"6/a/IV,II",
                "south" : MAZEDIR+"6/a/IV,IV",
                "west"  : MAZEDIR+"6/a/III,III"
           ]) );
}
