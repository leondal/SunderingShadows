#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/d/II,II",
                "south" : MAZEDIR+"1/d/II,IV",
                "east"  : MAZEDIR+"1/d/III,III"
           ]) );
}
