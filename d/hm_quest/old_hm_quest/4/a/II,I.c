#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "east"  : MAZEDIR+"4/a/III,I",
                "west"  : MAZEDIR+"4/a/I,I"
           ]) );
}
