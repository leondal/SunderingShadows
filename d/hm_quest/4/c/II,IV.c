#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : MAZEDIR+"4/c/II,III",
                "east"  : MAZEDIR+"4/c/III,IV",
                "south" : pass_exit("6","II,I")
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "north" : MAZEDIR+"4/c/II,III",
                "east"  : MAZEDIR+"4/c/III,IV",
                "south" : pass_exit("6","II,I")
           ]) );
  return 1;
}
