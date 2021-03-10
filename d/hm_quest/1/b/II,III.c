#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "east"  : MAZEDIR+"1/b/III,III",
                "west"  : MAZEDIR+"1/b/I,III"
           ]) );
}
