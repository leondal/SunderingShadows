#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/c/II,II",
                "east"  : MAZEDIR+"1/c/III,III",
                "west"  : MAZEDIR+"1/c/I,III"
           ]) );
}
