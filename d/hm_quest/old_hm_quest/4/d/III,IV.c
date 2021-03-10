#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : MAZEDIR+"4/d/III,III",
                "south" : pass_exit("6","III,I"),
                "east"  : MAZEDIR+"4/d/IV,IV"
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "north" : MAZEDIR+"4/d/III,III",
                "south" : pass_exit("6","III,I"),
                "east"  : MAZEDIR+"4/d/IV,IV"
           ]) );
  return 1;
}
