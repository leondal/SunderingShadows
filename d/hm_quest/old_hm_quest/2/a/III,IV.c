#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "south" : pass_exit("5","III,I"),
                "east"  : MAZEDIR+"2/a/IV,IV",
                "west"  : MAZEDIR+"2/a/II,IV"
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
                "south" : pass_exit("5","III,I"),
                "east"  : MAZEDIR+"2/a/IV,IV",
                "west"  : MAZEDIR+"2/a/II,IV"
           ]) );
  return 1;
}
