#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "south" : pass_exit("6","III,I"),
                "east"  : MAZEDIR+"4/b/IV,IV"
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "south" : pass_exit("6","III,I"),
                "east"  : MAZEDIR+"4/b/IV,IV"
           ]) );
  return 1;
}
