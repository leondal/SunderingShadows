#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "south" : MAZEDIR+"1/d/III,II",
                "east"  : MAZEDIR+"1/d/IV,I",
                "west"  : MAZEDIR+"1/d/II,I"
           ]) );
}
