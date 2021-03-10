#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : MAZEDIR+"4/b/IV,I",
                "east"  : pass_exit("5","I,II")
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
                "north" : MAZEDIR+"4/b/IV,I",
                "east"  : pass_exit("5","I,II")
           ]) );
  return 1;
}
