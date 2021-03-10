#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "east"  : MAZEDIR+"1/c/IV,I",
                "west"  : MAZEDIR+"1/c/II,I"
           ]) );
}
