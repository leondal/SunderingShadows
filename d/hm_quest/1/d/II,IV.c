#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/d/II,III",
                "east"  : MAZEDIR+"1/d/III,IV",
                "west"  : MAZEDIR+"1/d/I,IV"
           ]) );
}
