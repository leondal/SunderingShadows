#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : MAZEDIR+"4/b/II,II",
                "south" : MAZEDIR+"4/b/II,IV",
                "east"  : MAZEDIR+"4/b/III,III",
                "west"  : MAZEDIR+"4/b/I,III"
           ]) );
}
