#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/a/III,III",
                "south" : pass_exit("4","III,I")
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
            "north" : MAZEDIR+"1/a/III,III",
            "south" : pass_exit("4","III,I")
           ]) );
  return 1;
}
