#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(3);
  set_exits( ([
                "west"  : MAZEDIR+"3/b/III,II"
           ]) );
}
