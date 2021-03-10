#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "south" : MAZEDIR+"4/a/IV,III",
                "east"  : pass_exit("5","I,II"),
                "west"  : MAZEDIR+"4/a/III,II"
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
                "south" : MAZEDIR+"4/a/IV,III",
                "east"  : pass_exit("5","I,II"),
                "west"  : MAZEDIR+"4/a/III,II"
           ]) );
  return 1;
}
