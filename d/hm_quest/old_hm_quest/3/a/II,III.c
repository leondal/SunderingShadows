#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(3);
  set_exits( ([
                "north" : MAZEDIR+"3/a/II,II",
                "east"  : MAZEDIR+"3/a/III,III",
                "west"  : MAZEDIR+"3/a/I,III"
           ]) );
}
