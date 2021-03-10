#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : pass_exit("3","III,IV"),
                "east"  : MAZEDIR+"6/b/IV,I"
           ]) );
  set_pre_exit_functions( ({"north"}) , ({"go_north"}) );
}

int go_north()
{
  set_exits( ([
                "north" : pass_exit("3","III,IV"),
                "east"  : MAZEDIR+"6/b/IV,I"
           ]) );

  return 1;
}
