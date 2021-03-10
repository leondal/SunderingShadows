#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
	        "north" : MAZEDIR+"6/d/IV,III",
                "south" : pass_exit("9","IV,I")
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
	        "north" : MAZEDIR+"6/d/IV,III",
                "south" : pass_exit("9","IV,I")
           ]) );
  return 1;
}
