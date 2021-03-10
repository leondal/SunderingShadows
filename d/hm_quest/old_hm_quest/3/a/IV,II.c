#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(3);
  set_exits( ([
                "north" : MAZEDIR+"3/a/IV,I",
                "south" : MAZEDIR+"3/a/IV,III"
           ]) );
}
