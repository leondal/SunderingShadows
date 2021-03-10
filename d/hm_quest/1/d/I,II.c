#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/d/I,I",
                "south" : MAZEDIR+"1/d/I,III"
           ]) );
}
