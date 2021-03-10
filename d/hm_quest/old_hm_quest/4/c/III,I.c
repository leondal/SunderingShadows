#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : pass_exit("1","III,IV"),
                "east"  : MAZEDIR+"4/c/IV,I",
                "west"  : MAZEDIR+"4/c/II,I"
           ]) );
  set_pre_exit_functions( ({"north"}) , ({"go_north"}) );
}

int go_north()
{
  set_exits( ([
                "north" : pass_exit("1","III,IV"),
                "east"  : MAZEDIR+"4/c/IV,I",
                "west"  : MAZEDIR+"4/c/II,I"
           ]) );
  return 1;
}
