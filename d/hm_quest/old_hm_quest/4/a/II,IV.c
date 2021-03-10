#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "east"  : MAZEDIR+"4/a/III,IV",
                "west"  : MAZEDIR+"4/a/I,IV",
                "south" : pass_exit("6","II,I")
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "east"  : MAZEDIR+"4/a/III,IV",
                "west"  : MAZEDIR+"4/a/I,IV",
                "south" : pass_exit("6","II,I")
           ]) );
  return 1;
}
