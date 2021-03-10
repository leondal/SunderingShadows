#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
	        "east"  : MAZEDIR+"6/d/II,II",
                "west"  : pass_exit("5","IV,II")
           ]) );
  set_pre_exit_functions( ({"west"}) , ({"go_west"}) );
}

int go_west()
{
  set_exits( ([
	        "east"  : MAZEDIR+"6/d/II,II",
                "west"  : pass_exit("5","IV,II")
           ]) );
  return 1;
}
