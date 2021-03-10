#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/a/III,I",
                "west"  : MAZEDIR+"1/a/II,II"
           ]) );
}
