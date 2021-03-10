#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "east"  : MAZEDIR+"1/d/III,I",
                "west"  : MAZEDIR+"1/d/I,I"
           ]) );
}
