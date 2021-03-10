#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "east"  : MAZEDIR+"2/c/II,IV",
                "west"  : pass_exit("1","IV,IV")
           ]) );
  set_pre_exit_functions( ({"west"}) , ({"go_west"}) );
}

int go_west()
{
  set_exits( ([
                "east"  : MAZEDIR+"2/c/II,IV",
                "west"  : pass_exit("1","IV,IV")
           ]) );
  return 1;
}
