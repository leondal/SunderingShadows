#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "south" : pass_exit("9","IV,I"),
	        "west"  : MAZEDIR+"6/b/III,IV"
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "south" : pass_exit("9","IV,I"),
	        "west"  : MAZEDIR+"6/b/III,IV"
           ]) );
  return 1;
}
