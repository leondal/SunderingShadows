#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "east"  : MAZEDIR+"1/b/IV,I",
                "west"  : MAZEDIR+"1/b/II,I"
           ]) );
}
