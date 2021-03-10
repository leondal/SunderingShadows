#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/c/II,I",
                "south" : MAZEDIR+"1/c/II,III",
                "east"  : MAZEDIR+"1/c/III,II",
                "west"  : MAZEDIR+"1/c/I,II"
           ]) );
}
