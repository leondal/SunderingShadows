#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : MAZEDIR+"4/b/II,I",
                "south" : MAZEDIR+"4/b/II,III",
                "east"  : MAZEDIR+"4/b/III,II",
                "west"  : MAZEDIR+"4/b/I,II"
           ]) );
}
