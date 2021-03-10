#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(6);
  set_exits( ([
                "north" : pass_exit("3","III,IV"),
                "south" : MAZEDIR+"6/a/III,II",
                "east"  : MAZEDIR+"6/a/IV,I",
                "west"  : MAZEDIR+"6/a/II,I"
           ]) );
  set_pre_exit_functions( ({"north"}) , ({"go_north"}) );
}

int go_north()
{
  set_exits( ([
                "north" : pass_exit("3","III,IV"),
                "south" : MAZEDIR+"6/a/III,II",
                "east"  : MAZEDIR+"6/a/IV,I",
                "west"  : MAZEDIR+"6/a/II,I"
           ]) );

  return 1;
}
