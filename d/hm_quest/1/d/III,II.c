#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/d/III,I",
                "east"  : MAZEDIR+"1/d/IV,II"
           ]) );
}
