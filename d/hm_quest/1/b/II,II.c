#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/b/II,I",
                "east"  : MAZEDIR+"1/b/III,II",
                "west"  : MAZEDIR+"1/b/I,II"
           ]) );
}
