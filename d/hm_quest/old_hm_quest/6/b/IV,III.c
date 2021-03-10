#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "west"  : MAZEDIR+"6/b/III,III"
           ]) );
}
