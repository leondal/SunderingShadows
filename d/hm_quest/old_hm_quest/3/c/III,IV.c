#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(3);
  set_exits( ([
                "east"  : MAZEDIR+"3/c/IV,IV",
                "south" : pass_exit("6","III,I")
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "east"  : MAZEDIR+"3/c/IV,IV",
                "south" : pass_exit("6","III,I")
           ]) );
  return 1;
}
