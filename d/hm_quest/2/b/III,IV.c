#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : MAZEDIR+"2/b/III,III",
                "south" : pass_exit("5","III,I")
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "north" : MAZEDIR+"2/b/III,III",
                "south" : pass_exit("5","III,I")
           ]) );
  return 1;
}
