#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "west"  : MAZEDIR+"1/d/II,III"
           ]) );
}
